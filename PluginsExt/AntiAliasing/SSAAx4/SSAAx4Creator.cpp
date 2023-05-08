/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SSAAx4Creator.cpp
*/

#include "SSAAx4Creator.hpp"

namespace RayTracer::PluginsExt::AntiAliasing::SSAAx4 {
    SSAAx4Creator::~SSAAx4Creator()
    {
        for (auto element : _elements) {
            delete element;
        }
    }

    Filters::IFilter *SSAAx4Creator::create(const Scenes::ISetting &config, ILogger &logger)
    {
        SSAAx4Filter *element = new SSAAx4Filter(config, logger);
        _elements.push_back(element);
        return element;
    }
}
