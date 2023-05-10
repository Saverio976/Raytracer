/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "CameraCustomEntity.hpp"
#include "Api.hpp"
#include "CameraCustomCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Camera::FullCustom::CameraCustomCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::Camera::FullCustom::CameraCustomCreator *>(creator);
    }
}
