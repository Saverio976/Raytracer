/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCreator.cpp
*/

#include "CameraCreator.hpp"
#include "CameraEntity.hpp"

namespace RayTracer::PluginsExt::Camera {
    RayTracer::Entities::IEntity *CameraCreator::create(const Scenes::ISetting &config) {
        return new CameraEntity(config);
    }
}
