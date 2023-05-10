/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCreator.cpp
*/

#include "CameraCreator.hpp"
#include "CameraEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Camera {
    CameraCreator::~CameraCreator() {
        for (CameraEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *CameraCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        CameraEntity *element = new CameraEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
