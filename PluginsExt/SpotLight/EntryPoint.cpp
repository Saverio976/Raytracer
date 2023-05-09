/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "Api.hpp"
#include "SpotLightCreator.hpp"
#include "SpotLightEntity.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::SpotLight::SpotLightCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::SpotLight::SpotLightCreator *>(creator);
    }
}
