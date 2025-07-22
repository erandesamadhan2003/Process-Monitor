#ifndef PROCESS_CONFIG_H
#define PROCESS_CONFIG_H

#include <string>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

namespace ProcessMonitor {
    enum class RestartPolicy {
        NEVER, 
        ALWAYS, 
        ON_FAILURE, 
        UNLESS_STOPPED
    };

    enum class HealthCheckType {
        NONE,
        HTTP_GET,
        TCP_CONNECT,
        CUSTOM_SCRIPT,
        PROCESS_ALIVE
    };

    struct HealtCheckConfig {
        HealthCheckType type = HealthCheckType::PROCESS_ALIVE;
        std::string endpoint; // For HTTP checks
        int port = 0; // For TCP checks
        std::string scriptPath; // For custom scripts
        int timeout_seconds = 30; // Timeout for health checks
        int interval_seconds = 60; // how often to check
        int failure_threshold = 3; // Number of consecutive failures before marking unhealthy
        int success_threshold = 1; // Number of consecutive successes before marking healthy
    };

    struct ProcessConfig {
        std::string id; 
        std::string name; 
        std::string description; 

        // Execution settings
        std::string executable_path;
        std::string working_directory;
        std::vector<std::string> arguments;
        std::map<std::string, std::string> environment_variables;

        // User and permissions
        std::string run_as_user; 
        std::string run_as_group; 

        // restart policy
        RestartPolicy restart_policy = RestartPolicy::ON_FAILURE;
        int max_restarts = -1; // -1 means unlimited restarts
        int restart_delay_seconds = 5; // Delay between restarts
        int restart_backoff_multiplier = 2; // Exponential backoff multiplier
        int max_restart_delay_seconds = 300; // Maximum delay between restarts

        HealtCheckConfig health_check;

        bool monitor_cpu = true;
        bool monitor_memory = true;
        bool monitor_io = true;
        double cpu_threshold = 90.0; 
        double memory_threshold = 90.0;

        // logging 
        std::string log_file_path;
        bool capture_stdout = true;
        bool capture_stderr = true;
        int max_log_size_mb = 100; // Maximum size of log file in MB
        int max_log_files = 5; // Number of log files to keep

        bool auto_start = false;
        bool auto_start_on_crash = true;

        // Priority and scheduling
        int nice_level = 0; 
        long memory_limit_mb = -1; // -1 means no limit

        // Timing
        int startup_timeout_seconds = 30; // Timeout for process startup
        int shutdown_timeout_seconds = 30; // Timeout for process shutdown

        // Tags for grouping
        std::vector<std::string> tags; 

        // Custom metadata
        std::map<std::string, std::string> metadata;

        bool isValid() const {
            return !id.empty() && !name.empty() && !executable_path.empty();
        }

        // JSON serialization
        nlohmann::json toJson() const;
        static ProcessConfig fromJson(const nlohmann::json& json);
    
        // Default constructor
        ProcessConfig() = default;

        
        ProcessConfig(const std::string& id, const std::string& name, 
                 const std::string& executable) 
        : id(id), name(name), executable_path(executable) {}
    };

    std::string restartPolicyToString(RestartPolicy policy);
    RestartPolicy stringToRestartPolicy(const std::string& str);
    std::string healthCheckTypeToString(HealthCheckType type);
    HealthCheckType stringToHealthCheckType(const std::string& str);
}

#endif