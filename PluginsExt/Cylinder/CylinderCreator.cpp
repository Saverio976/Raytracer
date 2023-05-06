/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CylinderCreator.cpp
*/

#include "CylinderCreator.hpp"

namespace RayTracer::PluginsExt::Cylinder {
    CylinderCreator::~CylinderCreator() {
        for (CylinderEntity *element : this->_elements) {
            delete element;
        }
    }

    RayTracer::Entities::IEntity *CylinderCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        CylinderEntity *element = new CylinderEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
