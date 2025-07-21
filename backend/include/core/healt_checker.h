#ifndef HEALTH_CHECKER_H
#define HEALTH_CHECKER_H

#include <string>

namespace core {

    class HealthChecker {
    public:
        virtual ~HealthChecker() = default;

        // Perform health check on a process
        virtual void checkHealth(const std::string& processName) = 0;

        // Return true if the process is considered healthy
        virtual bool isHealthy(const std::string& processName) = 0;
    };

} // namespace core

#endif // HEALTH_CHECKER_H
