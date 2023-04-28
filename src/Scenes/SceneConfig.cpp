/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneConfig.cpp
*/

#include "SceneConfig.hpp"

namespace Raytracer::Scenes {
    SceneConfig::KeyNotFoundException::KeyNotFoundException(const std::string &key) {
        _msg = "Error key not found : " + key + "\n";
    };

    const char *SceneConfig::KeyNotFoundException::what() const throw() {
        return _msg.c_str();
    }

    SceneConfig::InvalidTypeSearchIndex::InvalidTypeSearchIndex(const std::string &key) {
        _msg = "Error invalid type for key : " + key + "\n";
    }

    const char *SceneConfig::InvalidTypeSearchIndex::what() const throw() {
        return _msg.c_str();
    }

    SceneConfig::SceneConfig(const std::shared_ptr<libconfig::Config> &config): _config(config), _setting(nullptr) {};

    bool SceneConfig::getSetting(const std::string &key) {
        try {
            _setting = &_config->lookup(key);
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
            return (false);
        }
        return (true);
    }

    int SceneConfig::getLength() {
        if (!_setting->isAggregate())
            return -1;
        return _setting->getLength();
    }
}
