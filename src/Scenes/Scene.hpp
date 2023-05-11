/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <string>
    #include <future>
    #include <vector>
    #include <memory>
    #include <mutex>
    #include <thread>
    #include <functional>
    #include "ILogger.hpp"
    #include "ISetting.hpp"
    #include "Image.hpp"
    #include "ICamera.hpp"
    #include "ILight.hpp"
    #include "IPrimitive.hpp"
    #include "SceneState.hpp"
    #include "Displayable.hpp"
    #include "EntityFactory.hpp"

namespace RayTracer::Scenes {
    /**
     * @brief The Scene class
     *
     * class that represent a scene
     */
    class Scene {
        public:
            Scene(ILogger &logger);
            ~Scene() = default;
            /**
             * @brief Scene config reloader
             *
             * @param config the config changed
             */
            void operator()(const ISetting &, const std::string &event);
            /**
             * @brief Renders the scene (execute internal process in the thread)
             *
             * So, it return imediatly after being called
             */
            void renders();
            /**
             * @brief Get the cameras
             *
             * @return the cameras
             */
            const std::vector<std::reference_wrapper<Entities::ICamera>> &getCameras() const;
            /**
             * @brief Get the cameras
             *
             * @return the cameras
             */
            std::vector<std::reference_wrapper<Entities::ICamera>> &getCameras();
            /**
             * @brief Check if the scene is ready (internal render thread is stopped)
             *
             * @return true if the scene is ready
             */
            bool isReady() const;
            /**
             * @brief Cancel the scene rendering
             */
            void cancel();
            /**
             * @brief wait until the end of the renders
             */
            void wait_end();
            /**
             * @brief Get the state
             *
             * @return the state
             */
            SceneState &getState();
            /**
             * @brief Get the state:
             *
             * @return the state
             */
            const SceneState &getState() const;
            /**
             * @brief Get the file base
             *
             * @return the file base
             */
            const std::string &getFileBase() const;
        protected:
        private:
            /**
             * @brief Load the scene
             *
             * @param setting the setting
             */
            void loadConfig(const ISetting &setting);
            /**
             * @brief Wait till the cancel is active (and do the changestate cancel)
             */
            void waitTillCancel();
            std::vector<std::reference_wrapper<Entities::ICamera>> _cameras;
            SceneState _state;
            std::future<void> _future;
            Displayable _displayable;
            ILogger &_logger;
    };
}

#endif /*SCENE_HPP_*/
