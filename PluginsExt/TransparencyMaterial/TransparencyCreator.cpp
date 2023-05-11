/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "TransparencyCreator.hpp"
#include "ILogger.hpp"
#include "TransparencyMaterial.hpp"

namespace RayTracer::PluginsExt::Transparency {
    TransparencyCreator::~TransparencyCreator() {
        for (TransparencyMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *TransparencyCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        TransparencyMaterial *element = new TransparencyMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
