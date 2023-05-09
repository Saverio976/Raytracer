/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "DiskCreator.hpp"
#include "ILogger.hpp"
#include "DiskEntity.hpp"

namespace RayTracer::PluginsExt::Disk {
    DiskCreator::~DiskCreator() {
        for (DiskEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *DiskCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        DiskEntity *element = new DiskEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}
