/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "ILogger.hpp"
#include "ISetting.hpp"
#include "Scene.hpp"
#include <future>
#include <string>

namespace RayTracer::Scenes {
    Scene::Scene(ILogger &logger):
        _logger(logger)
    {
    }

    void Scene::operator()(const ISetting &setting, const std::string &event) {
        if (event == "onChange") {
            this->loadConfig(setting);
        } else if (event == "onBeforeChange") {
            this->waitTillCancel();
        }
    }

    void Scene::renders() {
        if (!this->isReady()) {
            return;
        }
        this->_state.changeState(SceneState::States::RUNNING);
        this->_future = std::async(std::launch::async, [this] () {
            for (const std::reference_wrapper<Entities::ICamera> &camera : this->_cameras) {
                if (this->_state.getState() == SceneState::States::CANCELLED) {
                    break;
                }
                camera.get().render(this->_displayable, this->_state);
            }
        });
    }

    void Scene::cancel() {
        this->_state.changeState(SceneState::States::CANCELLED);
    }

    const std::vector<std::reference_wrapper<Entities::ICamera>> &Scene::getCameras() const {
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

    void Scene::loadConfig(const ISetting &setting)
    {
        std::shared_ptr<ISetting> settingWrapper;
        std::unique_ptr<ISetting> tmp;
        int length = 0;
        int length_two = 0;
        std::string name;

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
                _cameras.push_back(static_cast<Entities::ICamera &>(Factories::EntityFactory::getInstance().get(name, *tmp, _logger)));
            }
        }
        settingWrapper = setting.get("lights");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            name = (*settingWrapper).get(i)->getKey();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                _displayable.getLightList().push_back(static_cast<Entities::ILight &>(Factories::EntityFactory::getInstance().get(name, *tmp, _logger)));
            }
        }
        settingWrapper = setting.get("primitives");
        length = settingWrapper->getLength();
        for (int i = 0; i < length; i++) {
            length_two = (*settingWrapper).get(i)->getLength();
            name = (*settingWrapper).get(i)->getKey();
            for (int j = 0; j < length_two; j++) {
                tmp = settingWrapper->get(i)->get(j);
                _displayable.getPrimitiveList().push_back(static_cast<Entities::IPrimitive &>(Factories::EntityFactory::getInstance().get(name, *tmp, _logger)));
            }
        }
        this->renders();
    }

    void Scene::waitTillCancel()
    {
        this->_state.changeState(SceneState::States::CANCELLED);
        while (!this->isReady()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}
