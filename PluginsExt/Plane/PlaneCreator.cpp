/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "PlaneCreator.hpp"
#include "PlaneEntity.hpp"

namespace RayTracer::PluginsExt::Plane {
    RayTracer::Entities::IEntity *PlaneCreator::create(const Scenes::ISetting &config) {
        return new RayTracer::PluginsExt::Plane::PlaneEntity(config);
    }
}