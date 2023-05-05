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
    RayTracer::Entities::IEntity *PlaneCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        return new RayTracer::PluginsExt::Plane::PlaneEntity(config, logger);
    }
}
