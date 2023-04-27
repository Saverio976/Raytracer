/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.cpp
*/

#include "ConfigWrapper.hpp"

namespace Raytracer::Scenes {
    ConfigWrapper::SceneConfig::KeyNotFoundException::KeyNotFoundException(const std::string &key) {
        _msg = "Error key not found : " + key + "\n";
    };

    const char *ConfigWrapper::SceneConfig::KeyNotFoundException::what() const throw() {
        return _msg.c_str();
    }

    ConfigWrapper::SceneConfig::SceneConfig(const std::shared_ptr<libconfig::Config> &config): _config(config), _setting(nullptr) {};

    bool ConfigWrapper::SceneConfig::getSetting(const std::string &key) {
        try {
            _setting = &_config->lookup(key);
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
            return (false);
        }
        return (true);
    }

    bool ConfigWrapper::SceneConfig::getSetting(const int index) {
        try {
            *_setting[index];
        } catch (libconfig::SettingTypeException &e) {
            std::cerr << "Setting is invalid type :" << e.getPath() << std::endl;
            return (false);
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
            return (false);
        }
        return (true);
    }

    template<typename T>
    T ConfigWrapper::SceneConfig::getSettingValue() {
        T result;

        if (!_setting->exists(_setting->getPath()))
            throw ConfigWrapper::SceneConfig::KeyNotFoundException(_setting->getPath());
        result = _setting;
        return (result);
    }

    template<typename T>
    T ConfigWrapper::SceneConfig::getSettingValue(const std::string &key) {
        T result;

        if (!getSetting(key))
            throw ConfigWrapper::SceneConfig::KeyNotFoundException(key);
        result = _setting;
        return (result);
    }

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

    std::shared_ptr<ConfigWrapper::SceneConfig> ConfigWrapper::getScene() {
        return _scene;
    }
}