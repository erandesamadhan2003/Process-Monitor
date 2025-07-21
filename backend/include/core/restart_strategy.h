#ifndef RESTART_STRATEGY_H
#define RESTART_STRATEGY_H

#include <string>

namespace core {
    class RestartStrategy {
    public: 
        virtual ~RestartStrategy() = default;

        // Should the process be restarted based on its exit code?
        virtual bool shouldRestart(int exitCode) = 0;

        // Calculate delay (in seconds) before restarting
        virtual int calculateDelay(int attemptNumber) = 0;
    };
}

#endif