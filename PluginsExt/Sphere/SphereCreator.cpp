/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.cpp
*/

#include <memory>
#include "IEntity.hpp"
#include "ISetting.hpp"
#include "SphereCreator.hpp"
#include "SphereEntity.hpp"

namespace RayTracer::PluginsExt::Sphere {
    SphereCreator::~SphereCreator() {
        for (SphereEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *SphereCreator::create(const Scenes::ISetting &config) {
        SphereEntity *element = new SphereEntity(config);
        this->_elements.push_back(element);
        return element;
    }
}
