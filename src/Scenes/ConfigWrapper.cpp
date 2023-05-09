/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.cpp
*/

#include <string>
#include "Logger.hpp"
#include "ConfigWrapper.hpp"

namespace RayTracer::Scenes {
    const char *ConfigWrapper::ReadException::what() const throw() {
        return ("Error: can't read given file");
    }

    const char *ConfigWrapper::WriteException::what() const throw() {
        return ("Error: can't write given config");
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
            std::cerr << "Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
            throw ConfigWrapper::ReadException();
        }
        _scene = std::make_unique<SettingWrapper>(_config);
    }

    void ConfigWrapper::writeFile(const std::string &path) {
        try {
            _config->writeFile(path.c_str());
        } catch (libconfig::FileIOException &e) {
            std::cerr << "Writing error: " << e.what() << std::endl;
            throw ConfigWrapper::WriteException();
        }
    }

    std::shared_ptr<ISetting> ConfigWrapper::getSetting() const {
        return _scene;
    }
}
