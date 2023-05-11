/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntryPoint.cpp
*/

#include "Api.hpp"
#include "TriangleEntity.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Triangle::TriangleCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::Triangle::TriangleCreator *>(creator);
    }
}
