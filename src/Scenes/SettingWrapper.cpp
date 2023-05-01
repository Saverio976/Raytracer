/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SettingWrapper.cpp
*/

#include "SettingWrapper.hpp"

namespace RayTracer::Scenes {
    SettingWrapper::ParsingException::ParsingException(const std::string &key) {
        _msg = "Parsing error, cannot find : " + key + "\n";
    };

    const char *SettingWrapper::ParsingException::what() const throw() {
        return _msg.c_str();
    }

    SettingWrapper::SettingWrapper(const std::shared_ptr<libconfig::Config> &config): _config(config) {
        _setting = &config->getRoot();
    }

    SettingWrapper::SettingWrapper(const ISetting &src): _config(src.getConfig()) {
        if (!src.getPath().empty())
            _setting = &_config->lookup(src.getPath());
        else
            _setting = &_config->getRoot();
    }

    void SettingWrapper::getSetting(const std::string &key) {
        try {
            _setting = &_config->lookup(key);
        } catch (libconfig::SettingNotFoundException &e) {
            throw ParsingException(e.getPath());
        }
    }

    void SettingWrapper::getSetting(int index) {
        try {
            *_setting[index];
        } catch (libconfig::SettingTypeException &e) {
            throw ParsingException(e.getPath());
        } catch (libconfig::SettingNotFoundException &e) {
            throw ParsingException(e.getPath());
        }
    }

    int SettingWrapper::getLength() const {
        if (!_setting->isAggregate())
            return -1;
        return _setting->getLength();
    }

    std::string SettingWrapper::getPath() const {
        return (_setting->getPath());
    }

    std::string SettingWrapper::getKey() const {
        std::string path = _setting->getPath();
        int pos = 0;

        while (!_config->lookup(path).getName() && !path.empty()) {
            pos = static_cast<int>(path.find_last_of('.'));
            if (pos == -1)
                pos = 0;
            path = path.substr(pos, path.size());
        }
        return (_config->lookup(path).getName());
    }

    std::shared_ptr<libconfig::Config> SettingWrapper::getConfig() const {
        return (_config);
    }

    void SettingWrapper::moveTo(const std::string &key) {
        try {
            if (getPath().empty())
                getSetting(key);
            else
                _setting = &(*_setting)[key.c_str()];
        } catch (libconfig::SettingNotFoundException &e) {
            throw ParsingException(e.getPath());
        }
    }

    void SettingWrapper::moveTo(int index) {
        try {
            _setting = &(*_setting)[index];
        } catch (libconfig::SettingTypeException &e) {
            throw ParsingException(e.getPath());
        } catch (libconfig::SettingNotFoundException &e) {
            throw ParsingException(e.getPath());
        }
    }

    std::unique_ptr<ISetting> SettingWrapper::get(const std::string &key) const {
        std::unique_ptr<SettingWrapper> copy = std::make_unique<SettingWrapper>(*this);

        copy->moveTo(key);
        return copy;
    }

    std::unique_ptr<ISetting> SettingWrapper::get(int index) const {
        std::unique_ptr<SettingWrapper> copy = std::make_unique<SettingWrapper>(*this);

        copy->moveTo(index);
        return copy;
    }

    std::unique_ptr<ISetting> SettingWrapper::get() const {
        std::unique_ptr<SettingWrapper> copy = std::make_unique<SettingWrapper>(*this);

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
