/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntityLoader.cpp
*/

#include "EntityLoader.hpp"

namespace RayTracer::Plugins::Entities {
    EntityLoader::EntityLoader(const std::string &directory)
    : PluginLoader<EntityHandler, RayTracer::Entities::IEntity, Factories::EntityFactory>(directory)  { }

    void EntityLoader::loadEntities() {
        this->load();
    }
}
