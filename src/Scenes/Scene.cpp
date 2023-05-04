/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "ISetting.hpp"
#include "Scene.hpp"
#include <future>

namespace RayTracer::Scenes {
    void Scene::operator()(const ISetting &setting) {
        std::shared_ptr<ISetting> settingWrapper;
        std::unique_ptr<ISetting> tmp;
        int length = 0;
        int length_two = 0;
        std::string name;

        this->_state.changeState(SceneState::States::CANCELLED);
        while (!this->isReady()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        this->_cameras.clear();
        this->_displayable.getLightList().clear();
        this->_displayable.getPrimitiveList().clear();
        settingWrapper = setting.get("cameras");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            name = (*settingWrapper).get(i)->getKey();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                std::unique_ptr<Entities::ICamera> cameraPtr(static_cast<Entities::ICamera *>(Factories::EntityFactory::get(name, *tmp)));

                _cameras.push_back(std::move(cameraPtr));
            }
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
        this->_future = std::async(std::launch::async, [this] () {
            for (const std::unique_ptr<Entities::ICamera> &camera : this->_cameras) {
                if (this->_state.getState() == SceneState::States::CANCELLED) {
                    break;
                }
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

    bool Scene::isReady() const
    {
        try {
            return this->_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
        } catch (const std::future_error &e) {
            return true;
        }
    }

    void Scene::wait_end()
    {
        this->_future.wait();
    }
}
