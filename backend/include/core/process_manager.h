#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <string>

namespace core {
    class ProcessManager {
    public: 
        virtual ~ProcessManager() = default;

        // Process Lifecycle Management
        virtual bool startProcess(const std::string& processId) = 0;
        virtual bool stopProcess(const std::string& processId) = 0;
        virtual bool restartProcess(const std::string& processId) = 0;
        virtual bool killProcess(const std::string& processId) = 0;

        // Process Monitoring
        
    };
}

#endif 