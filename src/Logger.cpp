/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Logger.cpp
*/

#include <iostream>
#include <ctime>
#include <map>
#include <string>
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
        Logger::print(0, "FATAL", message);
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
        Logger::print(1, "ERROR", message);
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
        Logger::print(2, "WARN", message);
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
        Logger::print(3, "INFO", message);
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
        Logger::print(4, "DEBUG", message);
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
        Logger::print(5, "TRACE", message);
#endif
    }

    void Logger::print(int levelT, const std::string &level, const std::string &message)
    {
        static std::map<int, std::string> colors = {
            {0, "\033[31m"},
            {1, "\033[33m"},
            {2, "\033[34m"},
            {3, "\033[32m"},
            {4, "\033[38m"},
            {5, "\033[30m"},
            {6, "\033[0m"},
        };
        std::time_t rawtime;
        struct tm *timeinfo;
        std::string time;
        std::string mes;
        auto it = _callbacks.find(levelT);

        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);
        time = std::asctime(timeinfo);
        time.erase(time.find_last_of("\n"));
        mes = time + " [" + level + "] " + message;
        std::cerr << colors[levelT] << mes << colors[6] << std::endl;
        if (it != _callbacks.end()) {
            for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
                it1->second(mes);
            }
        }
    }

    void Logger::subscribeCallback(int type, const std::string &name, std::function<void(const std::string &)> callback)
    {
        if (_callbacks.find(type) == _callbacks.end()) {
            _callbacks.emplace(type, std::map<std::string, std::function<void(const std::string &)>>());
        }
        _callbacks[type].emplace(name, callback);
    }

    void Logger::unsubscribeCallback(int type, const std::string &name)
    {
        if (_callbacks.find(type) == _callbacks.end()) {
            return;
        }
        if (_callbacks[type].find(name) == _callbacks[type].end()) {
            return;
        }
        _callbacks[type].erase(name);
    }
}
