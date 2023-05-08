/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "SSAAx4Filter.hpp"
#include "Api.hpp"
#include "SSAAx4Creator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::AntiAliasing::SSAAx4::SSAAx4Creator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::AntiAliasing::SSAAx4::SSAAx4Creator *>(creator);
    }
}
