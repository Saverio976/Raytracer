/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "Api.hpp"
#include "MirrorCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Mirror::MirrorCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::Mirror::MirrorCreator *>(creator);
    }
}
