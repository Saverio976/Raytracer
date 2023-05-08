/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeCreator.cpp
*/

#include "ConeCreator.hpp"
#include "ConeEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Cone {
    RayTracer::Entities::IEntity *ConeCreator::create(const Scenes::ISetting &config, ILogger &logger)
    {
        return new RayTracer::PluginsExt::Cone::ConeEntity(config, logger);
    }

    ConeCreator::~ConeCreator()
    {
        for (auto element : _elements) {
            delete element;
        }
    }
}
