/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PixelThread.cpp
*/

#include "IDisplayable.hpp"
#include "PixelThread.hpp"
#include "IPrimitive.hpp"

namespace RayTracer::Images {
    PixelThread::PixelThread(const Scenes::IDisplayable &displayable, Color &color, const Images::Ray &ray) :
        _displayable(displayable),
        _color(color),
        _ray(ray)
    { }

    void PixelThread::operator()() {
        double distance = -1;
        double tmpDistance;
        size_t position = 0;
        const std::vector<std::unique_ptr<Entities::IPrimitive>> &list = _displayable.getPrimitiveList();
        std::optional<RayTracer::Entities::Transform::Vector3f> point;
        RayTracer::Entities::Transform::Vector3f pointFinal(0, 0, 0);

        for (size_t i = 0; i < list.size(); i++) {
            point = list[i]->isCollided(this->_ray);
            if (point == std::nullopt) {
                continue;
            }
            tmpDistance = point->getDistance(this->_ray.getOrigin());
            if (tmpDistance < distance || distance == -1) {
                distance = tmpDistance;
                position = i;
                pointFinal = *point;
            }
        }
        if (distance != -1) {
            this->_color = list[position]->getColor(this->_ray, this->_displayable, pointFinal);
        }
    }
}
