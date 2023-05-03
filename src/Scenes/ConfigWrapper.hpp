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
             * @brief an exception for when the file can't be read
             */
            class ReadException: public std::exception {
                public:
                    const char *what() const throw();
            };
            /**
             * @brief an exception for when the file can't be written
             */
            class WriteException: public std::exception {
                public:
                    const char *what() const throw();
            };
            /**
             * @brief read and parse the file at given path
             *
             * @param path the path to the file
             */
            void readFile(const std::string &path) override;
            /**
             * @brief writes the current config in a file at the given path
             *
             * @param path the path to the file
             */
            void writeFile(const std::string &path) override;
            /**
             * @brief returns the current SettingWrapper
             *
             * @return the current SettingWrapper
             */
            std::shared_ptr<ISetting> getSetting() const override;
        private:
            std::shared_ptr<libconfig::Config> _config;
            std::shared_ptr<ISetting> _scene;
    };
}

#endif //RAYTRACER_CONFIGWRAPPER_HPP
