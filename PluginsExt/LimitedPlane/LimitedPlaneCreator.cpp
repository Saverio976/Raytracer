/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** LimitedPlaneCreator.cpp
*/

#include "LimitedPlaneCreator.hpp"
#include "ILogger.hpp"
#include "LimitedPlaneEntity.hpp"

namespace RayTracer::PluginsExt::LimitedPlane {
    LimitedPlaneCreator::~LimitedPlaneCreator() {
        for (LimitedPlaneEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *LimitedPlaneCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        LimitedPlaneEntity *element = new LimitedPlaneEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
