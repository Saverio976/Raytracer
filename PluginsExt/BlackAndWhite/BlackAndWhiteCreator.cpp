/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** BlackAndWhiteCreator.cpp
*/

#include "BlackAndWhiteCreator.hpp"
#include "BlackAndWhiteFilter.hpp"

namespace RayTracer::PluginsExt::BlackAndWhite {
    BlackAndWhiteCreator::~BlackAndWhiteCreator()
    {
        for (auto element : _elements) {
            delete element;
        }
    }

    Filters::IFilter *BlackAndWhiteCreator::create(const Scenes::ISetting &config, ILogger &logger)
    {
        BlackAndWhiteFilter *element = new BlackAndWhiteFilter(config, logger);
        _elements.push_back(element);
        return element;
    }
}
