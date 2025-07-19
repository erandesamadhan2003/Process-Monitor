#include <iostream>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

class SimpleHTTPServer {
private:
    int server_fd;
    int port;
    
public:
    SimpleHTTPServer(int p = 8080) : port(p) {}
    
    bool start() {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0) {
            std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
            return false;
        }
        
        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            std::cerr << "Setsockopt failed: " << strerror(errno) << std::endl;
            return false;
        }
        
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);
        
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            std::cerr << "Bind failed: " << strerror(errno) << std::endl;
            return false;
        }
        
        if (listen(server_fd, 3) < 0) {
            std::cerr << "Listen failed: " << strerror(errno) << std::endl;
            return false;
        }
        
        std::cout << "Server is running on port " << port << std::endl;
        
        return true;
    }
    
    void run() {
        int addrlen = sizeof(struct sockaddr_in);
        struct sockaddr_in address;
        
        while (true) {
            int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            if (new_socket < 0) {
                std::cerr << "Accept failed: " << strerror(errno) << std::endl;
                continue;
            }
            
            std::thread(&SimpleHTTPServer::handle_client, this, new_socket).detach();
        }
    }
    
private:
    void handle_client(int client_socket) {
        char buffer[1024] = {0};
        read(client_socket, buffer, 1024);
        
        std::string response = "HTTP/1.1 200 OK\r\n";
        response += "Content-Type: application/json\r\n";
        response += "Access-Control-Allow-Origin: *\r\n";
        response += "\r\n";
        response += "{\n";
        response += "  \"message\": \"Welcome to Process Monitor API\",\n";
        response += "  \"status\": \"running\",\n";
        response += "  \"version\": \"1.0.0\"\n";
        response += "}\n";
        
        send(client_socket, response.c_str(), response.length(), 0);
        close(client_socket);
    }
};

int main() {
    std::cout << "Starting Process Monitor Server..." << std::endl;
    
    SimpleHTTPServer server(8080);
    
    if (!server.start()) {
        std::cerr << "Failed to start server" << std::endl;
        return 1;
    }
    
    server.run();
    
    return 0;
} 