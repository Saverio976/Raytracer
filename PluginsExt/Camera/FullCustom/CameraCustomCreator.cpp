/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCustomCreator.cpp
*/

#include "CameraCustomCreator.hpp"
#include "CameraCustomEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Camera::FullCustom {
    CameraCustomCreator::~CameraCustomCreator() {
        for (CameraCustomEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *CameraCustomCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        CameraCustomEntity *element = new CameraCustomEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
