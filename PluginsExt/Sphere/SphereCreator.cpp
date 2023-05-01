/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.cpp
*/

#include <memory>
#include "IEntity.hpp"
#include "ISetting.hpp"
#include "SphereCreator.hpp"
#include "SphereEntity.hpp"

namespace RayTracer::PluginsExt::Sphere {
    RayTracer::Entities::IEntity *SphereCreator::create(const Scenes::ISetting &config)
    {
        return new RayTracer::PluginsExt::Sphere::SphereEntity(config);
    }
}
