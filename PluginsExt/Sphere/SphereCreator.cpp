/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.cpp
*/

#include <memory>
#include "IEntity.hpp"
#include "ILogger.hpp"
#include "ISetting.hpp"
#include "SphereCreator.hpp"
#include "SphereEntity.hpp"

namespace RayTracer::PluginsExt::Sphere {
    RayTracer::Entities::IEntity *SphereCreator::create(const Scenes::ISetting &config, ILogger &logger)
    {
        return new RayTracer::PluginsExt::Sphere::SphereEntity(config, logger);
    }
}
