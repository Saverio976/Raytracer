/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_
    #include <list>
    #include <memory>
    #include <mutex>
    #include <thread>
    #include "Image.hpp"
    #include "ICamera.hpp"
    #include "SceneState.hpp"
    #include "Displayable.hpp"

class IConfig; // TODO: create an iconfig please

namespace RayTracer::Scenes {
    /**
     * @brief The Scene class
     *
     * class that represent a scene
     */
    class Scene {
        public:
            ~Scene();
            /**
             * @brief Scene config reloader
             *
             * @param config the config changed
             */
            void operator()(const IConfig &);
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
            const std::list<std::unique_ptr<Entities::ICamera>> &getCameras() const;
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
        protected:
        private:
            std::list<std::unique_ptr<Entities::ICamera>> _cameras;
            SceneState _state;
            std::thread thread;
            Displayable displayable;
    };
}

#endif /*SCENE_HPP_*/
