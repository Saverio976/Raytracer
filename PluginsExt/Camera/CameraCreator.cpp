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
    RayTracer::Entities::IEntity *CameraCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        return new CameraEntity(config, logger);
    }
}
