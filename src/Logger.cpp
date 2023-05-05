/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Logger.cpp
*/

#include <iostream>
#include <ctime>
#include "Logger.hpp"
#include "Parameters.hpp"

namespace RayTracer {
    void Logger::fatal(const std::string &message)
    {
        try {
            if (Parameters::getInstance().getInt("log-level") < 0) {
                return;
            }
        }
        catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("FATAL", message);
    }

    void Logger::error(const std::string &message)
    {
        try {
            if (Parameters::getInstance().getInt("log-level") < 1) {
                return;
            }
        } catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("ERROR", message);
    }

    void Logger::warn(const std::string &message)
    {
        try {
            if (Parameters::getInstance().getInt("log-level") < 2) {
                return;
            }
        } catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("WARN", message);
    }

    void Logger::info(const std::string &message)
    {
        try {
            if (Parameters::getInstance().getInt("log-level") < 3) {
                return;
            }
        } catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("INFO", message);
    }

    void Logger::debug(const std::string &message)
    {
#ifdef NDEBUG
        return;
#else
        try {
            if (Parameters::getInstance().getInt("log-level") < 4) {
                return;
            }
        } catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("DEBUG", message);
#endif
    }

    void Logger::trace(const std::string &message)
    {
#ifdef NDEBUG
        return;
#else
        try {
            if (Parameters::getInstance().getInt("log-level") < 5) {
                return;
            }
        } catch (const Parameters::KeyNotFoundError &e) {
            return;
        }
        Logger::print("TRACE", message);
#endif
    }

    void Logger::print(const std::string &level, const std::string &message)
    {
        std::time_t rawtime;
        struct tm *timeinfo;
        std::string time;

        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);
        time = std::asctime(timeinfo);
        time.erase(time.find_last_of("\n"));
        std::cerr << time << " [" << level << "] " << message << std::endl;
    }
}
