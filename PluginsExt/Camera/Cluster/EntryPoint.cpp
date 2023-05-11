/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "CameraClusterEntity.hpp"
#include "Api.hpp"
#include "CameraClusterCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::Camera::Clustered::CameraClusterCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::Camera::Clustered::CameraClusterCreator *>(creator);
    }
}
