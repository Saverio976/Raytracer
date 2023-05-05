/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.cpp
*/

#include "AmbientLightCreator.hpp"
#include "AmbientLightEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    RayTracer::Entities::IEntity *AmbientLightCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        return new AmbientLightEntity(config, logger);
    }
}
