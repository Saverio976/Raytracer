/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TorusCreator.cpp
*/

#include "TorusCreator.hpp"
#include "ILogger.hpp"
#include "TorusEntity.hpp"

namespace RayTracer::PluginsExt::Torus {
    TorusCreator::~TorusCreator() {
        for (TorusEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *TorusCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        TorusEntity *element = new TorusEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
