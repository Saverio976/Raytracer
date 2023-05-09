/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.cpp
*/

#include "PointLightCreator.hpp"
#include "PointLightEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::PointLight {
    PointLightCreator::~PointLightCreator() {
        for (PointLightEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *PointLightCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        PointLightEntity *element = new PointLightEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
