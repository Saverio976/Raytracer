/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.cpp
*/

#include "ConfigWrapper.hpp"

namespace Raytracer::Scenes {
    bool ConfigWrapper::readFile(const std::string &path) {
        std::shared_ptr<libconfig::Config> fileConfig = std::make_shared<libconfig::Config>();

        try {
            fileConfig->readFile(path.c_str());
            _config = fileConfig;
        } catch (libconfig::ParseException &e) {
            std::cerr << "Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
            return false;
        }
        _scene = std::make_unique<SceneConfig>(_config);
        return true;
    }

    bool ConfigWrapper::writeFile(const std::string &path) {
        try {
            _config->writeFile(path.c_str());
        } catch (libconfig::FileIOException &e) {
            std::cerr << "Writing error: " << e.what() << std::endl;
            return false;
        }
        return true;
    }

    std::shared_ptr<SceneConfig> ConfigWrapper::getScene() {
        return _scene;
    }
}
