/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TriangleCreator.cpp
*/

#include "TriangleCreator.hpp"
#include "ILogger.hpp"
#include "TriangleEntity.hpp"

namespace RayTracer::PluginsExt::Triangle {
    TriangleCreator::~TriangleCreator() {
        for (TriangleEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *TriangleCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        TriangleEntity *element = new TriangleEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
