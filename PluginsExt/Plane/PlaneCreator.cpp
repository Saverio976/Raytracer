/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "PlaneCreator.hpp"
#include "ILogger.hpp"
#include "PlaneEntity.hpp"

namespace RayTracer::PluginsExt::Plane {
    PlaneCreator::~PlaneCreator() {
        for (PlaneEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *PlaneCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        PlaneEntity *element = new PlaneEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
