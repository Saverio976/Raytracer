/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.hpp
*/

#ifndef SCENELOADER_HPP_
    #define SCENELOADER_HPP_
    #include <string>
    #include <functional>
    #include <map>
    #include <filesystem>
    #include "SettingWrapper.hpp"

namespace RayTracer::Scenes {
    /**
     * @brief The SceneLoader class
     *
     * class that represent a scene loader (take a config file)
     * and is an observer :eyes:
     */
    class SceneLoader {
        public:
            /**
             * @brief SceneLoader constructor (doesn't load anything)
             *
             * @param filePath the file path
             */
            SceneLoader(const std::string &filePath);
            ~SceneLoader();
            /**
             * @brief Subscribe to an event
             *
             * Available events : "onChange"
             *
             * @param event the event
             * @param std::function the function
             */
            void subscribe(const std::string &event, std::function<void(const SettingWrapper &)> func);
            /**
             * @brief Check if the file has been modified and call subscribed events in consequence
             */
            void update();
        protected:
        private:
            ConfigWrapper _configWrapper;
            std::map<std::string, std::function<void(const SettingWrapper &)>> _events;
            std::string _filePath;
            std::filesystem::file_time_type _lastWriteTime;
        };
}

#endif /*SCENELOADER_HPP_*/
