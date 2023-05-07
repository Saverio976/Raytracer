/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "LimitedCylinderEntity.hpp"
#include "Api.hpp"
#include "LimitedCylinderCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::LimitedCylinder::LimitedCylinderCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::LimitedCylinder::LimitedCylinderCreator *>(creator);
    }
}
