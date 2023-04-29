/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FilterLoader.cpp
*/

#include "FilterLoader.hpp"

namespace RayTracer::Plugins::Filters {
    FilterLoader::FilterLoader(const std::string &directory) :
    PluginLoader<FilterHandler, RayTracer::Filters::IFilter, Factories::FilterFactory>(directory) { }

    void FilterLoader::loadFilters() {
        this->load();
    }
}
