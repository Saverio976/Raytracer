/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

namespace RayTracer::Scenes {
    void Scene::operator()(const IConfig &config) {
        std::shared_ptr<ISetting> settingWrapper = config.getSetting();
        std::unique_ptr<ISetting> tmp;
        int length = 0;
        int length_two = 0;

        settingWrapper->getSetting("camera");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            tmp = settingWrapper->get(i);
            std::unique_ptr<Entities::ICamera> cameraPtr(static_cast<Entities::ICamera *>(Factories::EntityFactory::get(tmp->getKey(), *tmp)));

            _cameras.push_back(std::move(cameraPtr));
        }
        settingWrapper->getSetting("ligths");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                std::unique_ptr<Entities::ILight> lightPtr(static_cast<Entities::ILight *>(Factories::EntityFactory::get(tmp->getKey(), *tmp)));

                _displayable.getLightList().push_back(std::move(lightPtr));
            }
        }
        settingWrapper->getSetting("primitives");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                std::unique_ptr<Entities::IPrimitive> primitivePtr(static_cast<Entities::IPrimitive *>(Factories::EntityFactory::get(tmp->getKey(), *tmp)));

                _displayable.getPrimitiveList().push_back(std::move(primitivePtr));
            }
        }
    }

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

    const std::vector<std::unique_ptr<Entities::ICamera>> &Scene::getCameras() const {
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
