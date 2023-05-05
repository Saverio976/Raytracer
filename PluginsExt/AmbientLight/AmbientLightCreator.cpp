/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.cpp
*/

#include "AmbientLightCreator.hpp"
#include "AmbientLightEntity.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    AmbientLightCreator::~AmbientLightCreator() {
        for (AmbientLightEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *AmbientLightCreator::create(const Scenes::ISetting &config) {
        AmbientLightEntity *element = new AmbientLightEntity(config);
        this->_elements.push_back(element);
        return element;
    }
}
