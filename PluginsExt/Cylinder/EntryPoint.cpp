/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "CylinderEntity.hpp"
#include "Api.hpp"
#include "CylinderCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Cylinder::CylinderCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::Cylinder::CylinderCreator *>(creator);
    }
}
