/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.cpp
*/

#include <memory>
#include "IEntity.hpp"
#include "SphereCreator.hpp"
#include "SphereEntity.hpp"

namespace RayTracer::PluginsExt::Sphere {
    std::unique_ptr<RayTracer::Entities::IEntity> SphereCreator::create(const IConfig &config)
    {
        return std::make_unique<RayTracer::PluginsExt::Sphere::SphereEntity>(config);
    }
}
