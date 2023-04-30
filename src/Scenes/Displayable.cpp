/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Displayable.cpp
*/

#include "Displayable.hpp"

namespace RayTracer::Scenes {

    const std::vector<std::unique_ptr<Entities::ILight>>& Displayable::getLightList() const {
        return _lights;
    }

    std::vector<std::unique_ptr<Entities::ILight>>& Displayable::getLightList() {
        return _lights;
    }

    const std::vector<std::unique_ptr<Entities::IPrimitive>>& Displayable::getPrimitiveList() const {
        return _primitives;
    }

    std::vector<std::unique_ptr<Entities::IPrimitive>>& Displayable::getPrimitiveList() {
        return _primitives;
    }
}