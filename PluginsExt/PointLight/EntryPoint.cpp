/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "Api.hpp"
#include "PointLightCreator.hpp"
#include "PointLightEntity.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::PointLight::PointLightCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::PointLight::PointLightCreator *>(creator);
    }
}
