/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedConeCreator.cpp
*/

#include <vector>
#include "IEntityCreator.hpp"
#include "ILogger.hpp"
#include "LimitedConeCreator.hpp"

namespace RayTracer::PluginsExt::LimitedCone {
    RayTracer::Entities::IEntity *LimitedConeCreator::create(const Scenes::ISetting &config, ILogger &logger)
    {
        return new RayTracer::PluginsExt::LimitedCone::LimitedConeEntity(config, logger);
    }

    LimitedConeCreator::~LimitedConeCreator()
    {
        for (auto element : _elements) {
            delete element;
        }
    }
}