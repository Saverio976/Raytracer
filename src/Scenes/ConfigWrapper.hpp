/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.hpp
*/

#ifndef RAYTRACER_CONFIGWRAPPER_HPP
    #define RAYTRACER_CONFIGWRAPPER_HPP
    #include <iostream>
    #include <libconfig.h++>
    #include <memory>
    #include "IConfig.hpp"
    #include "SettingWrapper.hpp"

namespace RayTracer::Scenes {
    class ConfigWrapper: public IConfig {
        public:
            ConfigWrapper() = default;
            ~ConfigWrapper() override = default;
            /**
             * @brief read and parse the file at given path
             *
             * @param path the path to the file
             *
             * @return true if parsing worked, false otherwise
             */
            bool readFile(const std::string &path) override;
            /**
             * @brief writes the current config in a file at the given path
             *
             * @param path the path to the file
             *
             * @return true if writing worked, false otherwise
             */
            bool writeFile(const std::string &path) override;
            /**
             * @brief returns the current SettingWrapper
             *
             * @return the current SettingWrapper
             */
            std::shared_ptr<ISetting> getSetting() override;
        private:
            std::shared_ptr<libconfig::Config> _config;
            std::shared_ptr<ISetting> _scene;
    };
}

#endif //RAYTRACER_CONFIGWRAPPER_HPP
