/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "Api.hpp"
#include "LimitedPlaneCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::LimitedPlane::LimitedPlaneCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::LimitedPlane::LimitedPlaneCreator *>(creator);
    }
}
