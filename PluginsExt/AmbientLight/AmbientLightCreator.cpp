/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.cpp
*/

#include "AmbientLightCreator.hpp"
#include "AmbientLightEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    AmbientLightCreator::~AmbientLightCreator() {
        for (AmbientLightEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *AmbientLightCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        AmbientLightEntity *element = new AmbientLightEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
