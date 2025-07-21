#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <memory>

namespace logging {

    class Appender; // Forward declaration

    class Logger {
    public:
        enum class LogLevel {
            DEBUG,
            INFO,
            WARN,
            ERROR
        };

        virtual ~Logger() = default;

        // Log a message with a specific level
        virtual void log(LogLevel level, const std::string& message) = 0;

        // Set minimum log level
        virtual void setLevel(LogLevel level) = 0;

        // Add a logging output (console, file, etc.)
        virtual void addAppender(std::shared_ptr<Appender> appender) = 0;
    };

} // namespace logging

#endif // LOGGER_H
