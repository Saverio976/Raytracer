/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntityLoader.cpp
*/

#include "MaterialLoader.hpp"

namespace RayTracer::Plugins::Materials {
    MaterialLoader::MaterialLoader(const std::string &directory)
            : PluginLoader<MaterialHandler, RayTracer::Entities::IMaterial, Factories::MaterialFactory>(directory)  { }

    void MaterialLoader::loadMaterials() {
        this->load();
    }
}
