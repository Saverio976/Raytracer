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
    #include "SettingWrapper.hpp"

namespace RayTracer::Scenes {
    class ConfigWrapper {
        public:
            ConfigWrapper() = default;
            ~ConfigWrapper() = default;
            /**
             * @brief read and parse the file at given path
             *
             * @param path the path to the file
             *
             * @return true if parsing worked, false otherwise
             */
            bool readFile(const std::string &path);
            /**
             * @brief writes the current config in a file at the given path
             *
             * @param path the path to the file
             *
             * @return true if writing worked, false otherwise
             */
            bool writeFile(const std::string &path);
            /**
             * @brief returns the current SettingWrapper
             *
             * @return the current SettingWrapper
             */
            std::shared_ptr<SettingWrapper> getScene();
        private:
            std::shared_ptr<libconfig::Config> _config;
            std::shared_ptr<SettingWrapper> _scene;
    };
}

#endif //RAYTRACER_CONFIGWRAPPER_HPP
