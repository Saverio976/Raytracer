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
    #include <fstream>
    #include <filesystem>
    #include "FilterLoader.hpp"
    #include "EntityLoader.hpp"
    #include "ConfigWrapper.hpp"
    #include "ILogger.hpp"

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
            SceneLoader(const std::string &filePath, ILogger &logger);
            ~SceneLoader() = default;
            /**
             * @brief Subscribe to an event
             *
             * Available events : "onChange"
             *
             * @param event the event
             * @param std::function the function
             */
            void subscribe(const std::string &event, std::function<void(const ISetting &)> func);
            /**
             * @brief Check if the file has been modified and call subscribed events in consequence
             */
            void update();
        protected:
        private:
            std::unique_ptr<IConfig> _configWrapper;
            std::map<std::string, std::function<void(const ISetting &)>> _events;
            std::string _filePath;
            std::filesystem::file_time_type _lastWriteTime;
            std::unique_ptr<Plugins::Entities::EntityLoader> _entityLoader;
            std::unique_ptr<Plugins::Filters::FilterLoader> _filterLoader;
            ILogger &_logger;

        };
}

#endif /*SCENELOADER_HPP_*/
