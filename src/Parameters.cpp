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
            if (std::string(argv[i]).starts_with("--") &&
                    (i + 1 >= argc || std::string(argv[i + 1]).starts_with("--"))) {
                std::string key = std::string(argv[i] + 2);
                std::string value = "";
                _parameters->parseCmdArg(key, value);
            } else if (std::string(argv[i]).starts_with("--") && i + 1 < argc) {
                std::string key = std::string(argv[i] + 2);
                std::string value = std::string(argv[i + 1]);
                _parameters->parseCmdArg(key, value);
                i++;
            }
        }
    }

    const int Parameters::getInt(const std::string &key) const
    {
        try {
            return _valuesInt.at(key);
        } catch (const std::out_of_range &e) {
            throw KeyNotFoundError("key not found in Int:: " + key);
        }
    }

    const double Parameters::getDouble(const std::string &key) const
    {
        try {
            return _valuesDouble.at(key);
        } catch (const std::out_of_range &e) {
            throw KeyNotFoundError("key not found in Double:: " + key);
        }
    }

    const std::string &Parameters::getString(const std::string &key) const
    {
        try {
            return _valuesString.at(key);
        } catch (const std::out_of_range &e) {
            throw KeyNotFoundError("key not found in String:: " + key);
        }
    }

    void Parameters::set(const std::string &key, int value)
    {
        _valuesInt[key] = value;
    }

    void Parameters::set(const std::string &key, double value)
    {
        _valuesDouble[key] = value;
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
        double valueDouble;

        ss >> valueDouble;
        if (ss.fail()) {
            set(key, value);
            return;
        }
        if (value.find('.') != std::string::npos) {
            set(key, valueDouble);
            return;
        }
        ss.str(value);
        ss >> valueInt;
        if (ss.fail()) {
            set(key, valueDouble);
            return;
        }
        set(key, valueInt);
    }

    // -----------------------------------------------------------------------
    // Parameters::KeyNotFoundError
    // -----------------------------------------------------------------------

    Parameters::KeyNotFoundError::KeyNotFoundError(const std::string &key):
        _key(key)
    {
    }

    const char *Parameters::KeyNotFoundError::what() const noexcept
    {
        return _key.c_str();
    }
}
