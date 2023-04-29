/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

namespace RayTracer::Scenes {
    Scene::~Scene() {}

    void Scene::operator()(const IConfig &) {}

    void Scene::renders() {
        this->_thread = std::thread([&] {
            for (const std::unique_ptr<Entities::ICamera> &camera : this->_cameras) {
                if (this->_state.getState() == SceneState::States::CANCELLED)
                    break;
                camera->render(this->_displayable, this->_state);
            }
        });
    }

    void Scene::cancel() {
        this->_state.changeState(SceneState::States::CANCELLED);
    }

    const std::list<std::unique_ptr<Entities::ICamera>> &Scene::getCameras() const {
        return this->_cameras;
    }

    bool Scene::isReady() const {
        return !this->_thread.joinable();
    }

    void Scene::wait_end() {
        if (this->_thread.joinable())
            this->_thread.join();
    }
}