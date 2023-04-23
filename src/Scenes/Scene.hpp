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
    #include "Displayable.hpp"

class IConfig; // TODO: create an iconfig please

namespace RayTracer::Scenes {
    class Scene {
    public:
        class SceneState {
        public:
            enum class States {
                RUNNING,
                CANCELLED
            };
            States getState() const;
            void changeState(const States &state);
        private:
            States _state;
            std::mutex mutex;
        };
        ~Scene();
        void operator()(const IConfig &);
        void renders();
        const std::list<std::unique_ptr<Entities::ICamera>> &getCameras() const;
        bool isReady() const;
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
