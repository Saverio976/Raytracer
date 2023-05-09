/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SpotLightCreator.cpp
*/

#include "SpotLightCreator.hpp"
#include "SpotLightEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::SpotLight {
    SpotLightCreator::~SpotLightCreator() {
        for (SpotLightEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *SpotLightCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        SpotLightEntity *element = new SpotLightEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
