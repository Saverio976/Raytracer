/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeCreator.cpp
*/

#include "ConeCreator.hpp"
#include "ConeEntity.hpp"

namespace RayTracer::PluginsExt::Cone {
    RayTracer::Entities::IEntity *ConeCreator::create(const Scenes::ISetting &config) {
        return new RayTracer::PluginsExt::Cone::ConeEntity(config);
    }
}