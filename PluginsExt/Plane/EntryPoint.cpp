/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "PlaneEntity.hpp"
#include "Api.hpp"
#include "PlaneCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Plane::PlaneCreator();
    }

    void deleteCreator(void *creator, std::vector<void *> &elements)
    {
        for (void *element : elements)
            delete static_cast<RayTracer::PluginsExt::Plane::PlaneEntity *>(element);
        delete static_cast<RayTracer::PluginsExt::Plane::PlaneCreator *>(creator);
    }
}
