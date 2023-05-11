/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "ZebraCreator.hpp"
#include "ILogger.hpp"
#include "ZebraMaterial.hpp"

namespace RayTracer::PluginsExt::Zebra {
    ZebraCreator::~ZebraCreator() {
        for (ZebraMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *ZebraCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        ZebraMaterial *element = new ZebraMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
