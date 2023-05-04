/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "Api.hpp"
#include "AmbientLightCreator.hpp"
#include "AmbientLightEntity.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::AmbientLight::AmbientLightCreator();
    }

    void deleteCreator(void *creator, std::vector<void *> &elements)
    {
        for (void *element : elements)
            delete static_cast<RayTracer::PluginsExt::AmbientLight::AmbientLightEntity *>(element);
        delete static_cast<RayTracer::PluginsExt::AmbientLight::AmbientLightCreator *>(creator);
    }
}
