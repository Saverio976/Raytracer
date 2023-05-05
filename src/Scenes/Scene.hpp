/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_
    #include <future>
    #include <vector>
    #include <memory>
    #include <mutex>
    #include <thread>
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
            void operator()(const ISetting &);
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
            const std::vector<std::unique_ptr<Entities::ICamera>> &getCameras() const;
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
        protected:
        private:
            std::vector<std::unique_ptr<Entities::ICamera>> _cameras;
            SceneState _state;
            std::future<void> _future;
            Displayable _displayable;
            ILogger &_logger;
    };
}

#endif /*SCENE_HPP_*/
