/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "PlainMaterialCreator.hpp"
#include "ILogger.hpp"
#include "PlainMaterial.hpp"

namespace RayTracer::PluginsExt::PlainMaterial {
    PlainMaterialCreator::~PlainMaterialCreator() {
        for (PlainMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *PlainMaterialCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        PlainMaterial *element = new PlainMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
