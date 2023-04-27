/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PixelThread.cpp
*/

#include "PixelThread.hpp"
#include "IPrimitive.hpp"

namespace RayTracer::Images {
    PixelThread::PixelThread(const Scenes::Displayable &displayable, Color &color, const Images::Ray &ray) :
        _displayable(displayable),
        _color(color),
        _ray(ray)
    { }

    void PixelThread::operator()() {
        bool stop = false;

        while (!stop) {
            for (const Entities::IPrimitive &primitive : _displayable.getPrimitiveList()) {
                if (!primitive.isCollided(this->_ray.getStep()))
                    continue;
                stop = true;
                this->_color = primitive.getColor();
                break;
            }
            this->_ray++;
        }
    }
}