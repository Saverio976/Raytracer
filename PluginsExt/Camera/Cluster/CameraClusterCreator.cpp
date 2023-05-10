/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraClusterCreator.cpp
*/

#include "CameraClusterCreator.hpp"
#include "CameraClusterEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Camera::Clustered {
    CameraClusterCreator::~CameraClusterCreator() {
        for (CameraClusterEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *CameraClusterCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        CameraClusterEntity *element = new CameraClusterEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
