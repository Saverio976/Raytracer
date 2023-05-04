/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "SphereEntity.hpp"
#include "Api.hpp"
#include "SphereCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Sphere::SphereCreator();
    }

    void deleteCreator(void *creator, std::vector<void *> &elements)
    {
        for (void *element : elements)
            delete static_cast<RayTracer::PluginsExt::Sphere::SphereEntity *>(element);
        delete static_cast<RayTracer::PluginsExt::Sphere::SphereCreator *>(creator);
    }
}
