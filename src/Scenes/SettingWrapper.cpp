/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SettingWrapper.cpp
*/

#include "SettingWrapper.hpp"

namespace Raytracer::Scenes {
    SettingWrapper::KeyNotFoundException::KeyNotFoundException(const std::string &key) {
        _msg = "Error key not found : " + key + "\n";
    };

    const char *SettingWrapper::KeyNotFoundException::what() const throw() {
        return _msg.c_str();
    }

    SettingWrapper::InvalidTypeSearchIndex::InvalidTypeSearchIndex(const std::string &key) {
        _msg = "Error invalid type for key : " + key + "\n";
    }

    const char *SettingWrapper::InvalidTypeSearchIndex::what() const throw() {
        return _msg.c_str();
    }

    SettingWrapper::SettingWrapper(const std::shared_ptr<libconfig::Config> &config): _config(config) {
        _setting = &config->getRoot();
    }

    SettingWrapper::SettingWrapper(SettingWrapper &src): _config(src.getConfig()) {
        if (!src.getPath().empty())
            _setting = &_config->lookup(src.getPath());
        else
            _setting = &_config->getRoot();
    }

    bool SettingWrapper::getSetting(const std::string &key) {
        try {
            _setting = &_config->lookup(key);
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
            return (false);
        }
        return (true);
    }

    bool SettingWrapper::getSetting(int index) {
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

    int SettingWrapper::getLength() {
        if (!_setting->isAggregate())
            return -1;
        return _setting->getLength();
    }

    std::string SettingWrapper::getPath() {
        return (_setting->getPath());
    }

    std::shared_ptr<libconfig::Config> SettingWrapper::getConfig() {
        return (_config);
    }

    void SettingWrapper::moveTo(const std::string &key) {
        try {
            if (getPath().empty())
                getSetting(key);
            else
                _setting = &(*_setting)[key.c_str()];
        } catch (KeyNotFoundException &e) {
            std::cerr << e.what() << std::endl;
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
        }
    }

    void SettingWrapper::moveTo(int index) {
        try {
            _setting = &(*_setting)[index];
        } catch (libconfig::SettingTypeException &e) {
            std::cerr << "Setting is invalid type :" << e.getPath() << std::endl;
        } catch (libconfig::SettingNotFoundException &e) {
            std::cerr << "Setting not found at path :" << e.getPath() << std::endl;
        }
    }

    SettingWrapper SettingWrapper::operator[](const std::string &key) {
        SettingWrapper copy = SettingWrapper(*this);

        copy.moveTo(key);
        return copy;
    }

    SettingWrapper SettingWrapper::operator[](int index) {
        SettingWrapper copy = SettingWrapper(*this);

        copy.moveTo(index);
        return copy;
    }

    SettingWrapper::operator bool() const {
        return _setting->operator bool();
    }

    SettingWrapper::operator std::string() const {
        return _setting->operator std::string();
    }

    SettingWrapper::operator const char *() const {
        return _setting->operator const char *();
    }

    SettingWrapper::operator double() const {
        return _setting->operator double();
    }

    SettingWrapper::operator int() const {
        return _setting->operator int();
    }
}
