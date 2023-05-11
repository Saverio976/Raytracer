/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjCreator.cpp
*/

#include "ObjCreator.hpp"
#include "ILogger.hpp"
#include "ObjEntity.hpp"

namespace RayTracer::PluginsExt::Obj {
    ObjCreator::~ObjCreator() {
        for (ObjEntity *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IEntity *ObjCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        ObjEntity *element = new ObjEntity(config, logger);
        this->_elements.push_back(element);
        return element;
    }
}