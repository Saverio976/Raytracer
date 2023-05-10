/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PixelThread.cpp
*/

#include <functional>
#include <vector>
#include "Color.hpp"
#include "IDisplayable.hpp"
#include "PixelThread.hpp"
#include "IPrimitive.hpp"
#include "ILight.hpp"

namespace RayTracer::Images {
    PixelThread::PixelThread(const Scenes::IDisplayable &displayable, std::vector<std::reference_wrapper<Color>> colors, const Images::Ray &ray) :
        _displayable(displayable),
        _colors(colors),
        _ray(ray)
    {
    }

    void PixelThread::operator()() {
        double distance = -1;
        double tmpDistance;
        size_t position = 0;
        Color final(0, 0, 0, 255);
        const std::vector<std::reference_wrapper<Entities::IPrimitive>> &list = _displayable.getPrimitiveList();
        std::optional<RayTracer::Entities::Transform::Vector3f> point;
        RayTracer::Entities::Transform::Vector3f pointFinal(0, 0, 0);

        for (size_t i = 0; i < list.size(); i++) {
            point = list[i].get().isCollided(this->_ray);
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
            final = list[position].get().getColor(this->_ray, this->_displayable, pointFinal);
        } else {
            try {
                final = this->_displayable.getAmbientLight().getColor();
            } catch (Scenes::IDisplayable::IDisplayableException &exception) {
                final = Color(0, 0, 0, 255);
            }
        }
        for (auto it : _colors) {
            it.get() = final;
        }
    }
}
