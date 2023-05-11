/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "RefractionCreator.hpp"
#include "ILogger.hpp"
#include "RefractionMaterial.hpp"

namespace RayTracer::PluginsExt::Refraction {
    RefractionCreator::~RefractionCreator() {
        for (RefractionMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *RefractionCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        RefractionMaterial *element = new RefractionMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
