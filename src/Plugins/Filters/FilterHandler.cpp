/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FilterHandler.cpp
*/

#include "FilterHandler.hpp"

namespace RayTracer::Plugins::Filters {
    FilterHandler::FilterHandler(const std::string &filePath) : _handler(filePath) { }

    RayTracer::Filters::IFilter &FilterHandler::get(const RayTracer::Scenes::ISetting &setting) {
        return this->_handler.get(setting);
    }
}
