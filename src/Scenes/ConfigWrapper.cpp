/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.cpp
*/

#include <string>
#include "ILogger.hpp"
#include "Logger.hpp"
#include "ConfigWrapper.hpp"

namespace RayTracer::Scenes {
    ConfigWrapper::ConfigWrapper(ILogger &logger):
        _logger(logger)
    {
    }

    ConfigWrapper::ReadException::ReadException(const std::string &message):
        _message(message)
    {
    }

    ConfigWrapper::WriteException::WriteException(const std::string &message):
        _message(message)
    {
    }

    const char *ConfigWrapper::ReadException::what() const throw() {
        return _message.c_str();
    }

    const char *ConfigWrapper::WriteException::what() const throw() {
        return _message.c_str();
    }

    void ConfigWrapper::readFile(const std::string &path) {
        std::shared_ptr<libconfig::Config> fileConfig = std::make_shared<libconfig::Config>();

        try {
            fileConfig->readFile(path.c_str());
            _config = fileConfig;
        } catch (libconfig::ParseException &e) {
            std::string file = e.getFile();
            std::string line = std::to_string(e.getLine());
            std::string error = e.getError();
            std::string message = "Parse error at " + file + ":" + line + " - " + error;
            throw ConfigWrapper::ReadException(message);
        }
        _scene = std::make_unique<SettingWrapper>(_config);
    }

    void ConfigWrapper::writeFile(const std::string &path) {
        try {
            _config->writeFile(path.c_str());
        } catch (libconfig::FileIOException &e) {
            std::string message = e.what();
            throw ConfigWrapper::WriteException("Wrting error: " + path + ": "+ message);
        }
    }

    std::shared_ptr<ISetting> ConfigWrapper::getSetting() const {
        return _scene;
    }
}
