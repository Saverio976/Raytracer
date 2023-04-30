/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#include <memory>
#include <sstream>
#include <string>
#include "Parameters.hpp"

namespace RayTracer {
    std::unique_ptr<Parameters> Parameters::_parameters = nullptr;

    Parameters &Parameters::getInstance()
    {
        if (!_parameters)
            _parameters.reset(new Parameters());
        return *_parameters;
    }

    void Parameters::parseCmdArgs(int argc, char **argv)
    {
        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]).starts_with("--") && i + 1 < argc) {
                std::string key = std::string(argv[i] + 2);
                std::string value = std::string(argv[i + 1]);
                _parameters->parseCmdArg(key, value);
                i++;
            }
        }
    }

    const int Parameters::getInt(const std::string &key) const
    {
        return _valuesInt.at(key);
    }

    const float Parameters::getFloat(const std::string &key) const
    {
        return _valuesFloat.at(key);
    }

    const std::string &Parameters::getString(const std::string &key) const
    {
        return _valuesString.at(key);
    }

    void Parameters::set(const std::string &key, int value)
    {
        _valuesInt[key] = value;
    }

    void Parameters::set(const std::string &key, float value)
    {
        _valuesFloat[key] = value;
    }

    void Parameters::set(const std::string &key, const std::string &value)
    {
        _valuesString[key] = value;
    }

    Parameters::Parameters()
    {
    }

    void Parameters::parseCmdArg(const std::string &key, const std::string &value)
    {
        std::stringstream ss(value);
        int valueInt;
        float valueFloat;

        ss >> valueFloat;
        if (ss.fail()) {
            set(key, value);
            return;
        }
        if (value.find('.') != std::string::npos) {
            set(key, valueFloat);
            return;
        }
        ss.str(value);
        ss >> valueInt;
        if (ss.fail()) {
            set(key, valueFloat);
            return;
        }
        set(key, valueInt);
    }
}
