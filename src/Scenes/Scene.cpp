/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "ISetting.hpp"
#include "Scene.hpp"

namespace RayTracer::Scenes {
    void Scene::operator()(const ISetting &setting) {
        std::shared_ptr<ISetting> settingWrapper;
        std::unique_ptr<ISetting> tmp;
        int length = 0;
        int length_two = 0;
        std::string name;

        settingWrapper = setting.get("cameras");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            tmp = settingWrapper->get(i);
            std::unique_ptr<Entities::ICamera> cameraPtr(static_cast<Entities::ICamera *>(Factories::EntityFactory::get("camera", *tmp)));

            _cameras.push_back(std::move(cameraPtr));
        }
        settingWrapper = setting.get("lights");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            name = (*settingWrapper).get(i)->getKey();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                std::unique_ptr<Entities::ILight> lightPtr(static_cast<Entities::ILight *>(Factories::EntityFactory::get(name, *tmp)));

                _displayable.getLightList().push_back(std::move(lightPtr));
            }
        }
        settingWrapper = setting.get("primitives");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            name = (*settingWrapper).get(i)->getKey();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                std::unique_ptr<Entities::IPrimitive> primitivePtr(static_cast<Entities::IPrimitive *>(Factories::EntityFactory::get(name, *tmp)));

                _displayable.getPrimitiveList().push_back(std::move(primitivePtr));
            }
        }
    }

    void Scene::renders() {
        this->_state.changeState(SceneState::States::RUNNING);
        this->_thread = std::thread([&] () -> void * {
            try {
                for (const std::unique_ptr<Entities::ICamera> &camera : this->_cameras) {
                    if (this->_state.getState() == SceneState::States::CANCELLED)
                        break;
                    camera->render(this->_displayable, this->_state);
                }
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            return nullptr;
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
