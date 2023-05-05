/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCreator.cpp
*/

#include "CameraCreator.hpp"
#include "CameraEntity.hpp"

namespace RayTracer::PluginsExt::Camera {
    CameraCreator::~CameraCreator() {
        for (CameraEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *CameraCreator::create(const Scenes::ISetting &config) {
        CameraEntity *element = new CameraEntity(config);
        this->_elements.push_back(element);
        return element;
    }
}
