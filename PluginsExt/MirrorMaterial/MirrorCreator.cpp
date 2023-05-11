/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "MirrorCreator.hpp"
#include "ILogger.hpp"
#include "MirrorMaterial.hpp"

namespace RayTracer::PluginsExt::Mirror {
    MirrorCreator::~MirrorCreator() {
        for (MirrorMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *MirrorCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        MirrorMaterial *element = new MirrorMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
