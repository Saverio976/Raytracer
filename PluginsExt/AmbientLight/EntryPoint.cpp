/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include "Api.hpp"
#include "AmbientLightCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::AmbientLight::AmbientLightCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::AmbientLight::AmbientLightCreator *>(creator);
    }
}
