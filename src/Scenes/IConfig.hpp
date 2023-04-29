/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IConfig.hpp
*/

#ifndef ICONFIG_HPP_
	#define ICONFIG_HPP_
    #include <iostream>
    #include <memory>
    #include "ISetting.hpp"

namespace RayTracer::Scenes {
    class IConfig {
        public:
            virtual ~IConfig() = default;
            /**
             * @brief read and parse the file at given path
             *
             * @param path the path to the file
             *
             * @return true if parsing worked, false otherwise
             */
            virtual bool readFile(const std::string &path) = 0;
            /**
             * @brief writes the current config in a file at the given path
             *
             * @param path the path to the file
             *
             * @return true if writing worked, false otherwise
             */
            virtual bool writeFile(const std::string &path) = 0;
            /**
             * @brief returns the current SettingWrapper
             *
             * @return the current SettingWrapper
             */
            virtual std::shared_ptr<ISetting> getSetting() = 0;
    };
}

#endif /*ICONFIG_HPP_*/