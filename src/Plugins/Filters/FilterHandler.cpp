/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FilterHandler.cpp
*/

#include "FilterHandler.hpp"

namespace RayTracer::Plugins::Filters {
    FilterHandler::FilterHandler(const std::string &filePath) : _handler(filePath) { }

    std::unique_ptr <RayTracer::Filters::IFilter> FilterHandler::get(const RayTracer::Scenes::IConfig &config) {
        return this->_handler.get(config);
    }
}