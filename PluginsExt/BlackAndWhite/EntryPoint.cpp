/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntryPoint.cpp
*/

#include <vector>
#include "BlackAndWhiteFilter.hpp"
#include "Api.hpp"
#include "BlackAndWhiteCreator.hpp"

extern "C" {
    void *getCreator(void)
    {
        return new RayTracer::PluginsExt::BlackAndWhite::BlackAndWhiteCreator();
    }

    void deleteCreator(void *creator)
    {
        delete static_cast<RayTracer::PluginsExt::BlackAndWhite::BlackAndWhiteCreator *>(creator);
    }
}
