#include <crow.h>
#include <crow/middlewares/cors.h>

int main() {
    crow::App<crow::CORSHandler> app;

    // CORS configuration
    auto& cors = app.get_middleware<crow::CORSHandler>();
    cors.global()
        .origin("http://localhost:5173")  
        .methods("GET"_method, "POST"_method, "PUT"_method, "DELETE"_method)
        .headers("Content-Type", "Authorization")
        .allow_credentials()
        .max_age(3600);

    // REST Route
    CROW_ROUTE(app, "/")([]() {
        std::cout << "Route added Successfully" << std::endl;

        crow::json::wvalue response;
        response["message"] = "Welcome to first cpp project!";
        response["author"] = "Samadhan";

        return response;
    });

    // WebSocket Route
    CROW_WEBSOCKET_ROUTE(app, "/ws")
    .onopen([](crow::websocket::connection& conn) {
        CROW_LOG_INFO << "WebSocket connection opened";
        conn.send_text("Welcome Samadhan!");
    })
    .onmessage([](crow::websocket::connection& conn, const std::string& data, bool is_binary) {
        conn.send_text("Echo: " + data);
    })
    .onclose([](crow::websocket::connection& conn, const std::string& reason, uint16_t close_code) {
        CROW_LOG_INFO << "WebSocket closed: " << reason << " (Code: " << close_code << ")";
    });

    // HTTPS configuration (optional)
    // Uncomment if you have cert.pem and key.pem in your project root
    // app.ssl_file("cert.pem", "key.pem");

    app.port(18080).multithreaded().run();
    return 0;
}