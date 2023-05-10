/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.hpp
*/

#ifndef SCENELOADER_HPP_
    #define SCENELOADER_HPP_
    #include <exception>
#include <string>
    #include <functional>
    #include <map>
    #include <fstream>
    #include <filesystem>
    #include "FilterLoader.hpp"
    #include "EntityLoader.hpp"
    #include "MaterialLoader.hpp"
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
            class BadFileError : public std::exception {
                public:
                    BadFileError(const std::string &error);
                    const char *what() const throw() override;
                private:
                    std::string _error;
            };
            /**
             * @brief SceneLoader constructor (doesn't load anything)
             *
             * Throw BadFileError if the filePath doesn't ends with '.yaax'
             * Throw BadFileError if the filePath is not a regular file
             *
             * @param filePath the file path
             */
            SceneLoader(const std::string &filePath, ILogger &logger);
            ~SceneLoader() = default;
            /**
             * @brief Subscribe to an event
             *
             * Available events : "onChange", "onBeforeChange"
             * onChange : called when the scene is changed
             * onBeforeChange : called before reloading the scene
             *
             * @param event the event
             * @param std::function the function
             */
            void subscribe(const std::string &event, std::function<void(const ISetting &)> func);
            /**
             * @brief Check if the file has been modified and call subscribed events in consequence
             */
            void update();
            /**
             * @brief Check if the file passed can be proceed by the class
             *
             * @param filePath the filePaht to check
             */
            static void checkGoodFile(const std::string &filePath);
        protected:
        private:
            std::unique_ptr<IConfig> _configWrapper;
            std::map<std::string, std::function<void(const ISetting &)>> _events;
            std::string _filePath;
            std::filesystem::file_time_type _lastWriteTime;
            std::unique_ptr<Plugins::Entities::EntityLoader> _entityLoader;
            std::unique_ptr<Plugins::Filters::FilterLoader> _filterLoader;
            std::unique_ptr<Plugins::Materials::MaterialLoader> _materialLoader;
            ILogger &_logger;

        };
}

#endif /*SCENELOADER_HPP_*/
