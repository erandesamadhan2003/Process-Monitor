#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <string>

namespace core {
    class ProcessManager {
    public: 
        virtual ~ProcessManager() = default;

        // start a process by name
        virtual void startProcess(const std::string& processName) = 0;

        //stop a process by name
        virtual void stopProcess(const std::string& processName) = 0;

        // Get the status of a process by name
        virtual std::string getProcessStatus(const std::string& processName) = 0;

    };
}

#endif 