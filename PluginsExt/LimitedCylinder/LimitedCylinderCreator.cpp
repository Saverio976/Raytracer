/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderCreator.cpp
*/

#include "LimitedCylinderCreator.hpp"

namespace RayTracer::PluginsExt::LimitedCylinder {
    LimitedCylinderCreator::~LimitedCylinderCreator() {
        for (LimitedCylinderEntity *element : this->_elements) {
            delete element;
        }
    }

    RayTracer::Entities::IEntity *LimitedCylinderCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        LimitedCylinderEntity *element = new LimitedCylinderEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
