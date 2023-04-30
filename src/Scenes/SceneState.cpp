/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SceneState.cpp
*/

#include "SceneState.hpp"

namespace RayTracer::Scenes {
    SceneState::SceneState() {
        this->_state = SceneState::States::CANCELLED;
    }

    SceneState::States SceneState::getState() const {
        return this->_state;
    }

    void SceneState::changeState(const RayTracer::Scenes::SceneState::States &state) {
        this->mutex.lock();
        this->_state = state;
        this->mutex.unlock();
    }
}
