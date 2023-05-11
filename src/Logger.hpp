/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Logger.hpp
*/

#ifndef RAYLOGGER_HPP
    #define RAYLOGGER_HPP

    #include <map>
#include <string>
    #include "ILogger.hpp"

namespace RayTracer {
    /**
     * @brief Logger singleton
     *
     * LogLevel:
     * -1 - no messages
     * 0 - only `fatal` are displayed
     * 1 - `error` and `fatal` are displayed
     * 2 - `warn`, `error` and `fatal` are displayed
     * 3 - `info`, `warn`, `error` and `fatal` are displayed
     * 4 - `debug`, `info`, `warn`, `error` and `fatal` are displayed
     * 5 - `trace`, `debug`, `info`, `warn`, `error` and `fatal` are displayed
     *
     * Attention:
     * `debug` and `trace` will only do something in debug mode compilation.
     * (`set(CMAKE_BUILD_TYPE Debug)` in `CMakeLists.txt`)
     */
    class Logger : public ILogger {
        public:
            /**
             * @brief Logger fata
             * 
             * Means that something critical is broken, and the application
             * cannot continue to do any more useful work without the
             * intervention of an engineer.
             *
             * @param message the message
             */
            void fatal(const std::string &message) final;
            /**
             * @brief Logger error
             *
             * The ERROR log level is used to represent error conditions in
             * an application that prevent a specific operation from running,
             * but the application itself can continue working even if it is
             * at a reduced level of functionality or performance.
             *
             * @param message the message
             */
            void error(const std::string &message) final;
            /**
             * @brief Logger warn
             *
             * Messages logged at the WARN level typically indicate that
             * something unexpected happened, but the application can recover
             * and continue to function normally.
             *
             * @param message the message
             */
            void warn(const std::string &message) final;
            /**
             * @brief Logger info
             *
             * INFO-level messages indicate events in the system that are
             * significant to the business purpose of the application. Such
             * events are logged to show that the system is operating normally.
             *
             * @param message the message
             */
            void info(const std::string &message) final;
            /**
             * @brief Logger debug
             *
             * The DEBUG level is used for logging messages that help
             * developers find out what went wrong during a debugging session.
             *
             * @param message the message
             */
            void debug(const std::string &message) final;
            /**
             * @brief Logger trace
             *
             * The TRACE level is used for tracing the path of code execution
             * in a program.
             *
             * @param message the message
             */
            void trace(const std::string &message) final;
            /**
             * @brief Logger subscribe
             *
             * @param type the type to subscribe for
             * @param name the name
             * @param callback the callback
             */
            void subscribeCallback(int type, const std::string &name, std::function<void (const std::string &)> callback) final;
            /**
             * @brief Logger remove
             *
             * @param type the type
             * @param name the name
             */
            void unsubscribeCallback(int type, const std::string &name) final;

        private:
            void print(int levelT, const std::string &level, const std::string &message);
            std::map<int, std::map<std::string, std::function<void(const std::string &)>>> _callbacks;
    };
}

#endif
