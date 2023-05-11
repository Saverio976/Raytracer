/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntryPoint.cpp
*/

#include "Api.hpp"
#include "ObjEntity.hpp"
#include "ObjCreator.hpp"

extern "C" {
void *getCreator(void)
{
    return new RayTracer::PluginsExt::Obj::ObjCreator();
}

void deleteCreator(void *creator)
{
    delete static_cast<RayTracer::PluginsExt::Obj::ObjCreator *>(creator);
}
}
