/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "CameraEntity.hpp"
#include "Api.hpp"
#include "CameraCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Camera::CameraCreator();
    }

    void deleteCreator(void *creator, std::vector<void *> &elements)
    {
        for (void *element : elements)
            delete static_cast<RayTracer::PluginsExt::Camera::CameraEntity *>(element);
        delete static_cast<RayTracer::PluginsExt::Camera::CameraCreator *>(creator);
    }
}
