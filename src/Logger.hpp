/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Logger.hpp
*/

#ifndef RAYLOGGER_HPP
    #define RAYLOGGER_HPP

    #include <string>

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
    class Logger {
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
            static void fatal(const std::string &message);
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
            static void error(const std::string &message);
            /**
             * @brief Logger warn
             *
             * Messages logged at the WARN level typically indicate that
             * something unexpected happened, but the application can recover
             * and continue to function normally.
             *
             * @param message the message
             */
            static void warn(const std::string &message);
            /**
             * @brief Logger info
             *
             * INFO-level messages indicate events in the system that are
             * significant to the business purpose of the application. Such
             * events are logged to show that the system is operating normally.
             *
             * @param message the message
             */
            static void info(const std::string &message);
            /**
             * @brief Logger debug
             *
             * The DEBUG level is used for logging messages that help
             * developers find out what went wrong during a debugging session.
             *
             * @param message the message
             */
            static void debug(const std::string &message);
            /**
             * @brief Logger trace
             *
             * The TRACE level is used for tracing the path of code execution
             * in a program.
             *
             * @param message the message
             */
            static void trace(const std::string &message);

        private:
            static void print(const std::string &level, const std::string &message);
    };
}

#endif
