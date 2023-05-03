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
        double distance = -1;
        double tmpDistance;
        size_t position = 0;
        const std::vector<std::unique_ptr<Entities::IPrimitive>> &list = _displayable.getPrimitiveList();
        std::optional<RayTracer::Entities::Transform::Vector3f> point;

        std::cout << "je passes pour le calcul du pixel" << std::endl;
        for (size_t i = 0; i < list.size(); i++) {
            std::cout << this->_ray.getOrigin().getX() << " " << this->_ray.getOrigin().getY() << " " << this->_ray.getOrigin().getZ() <<std::endl;
            point = list[i]->isCollided(this->_ray);
            if (point == std::nullopt)
                continue;
            tmpDistance = point->getDistance(this->_ray.getOrigin());
            if (tmpDistance < distance || distance == -1) {
                distance = tmpDistance;
                position = i;
            }
        }
        //std::cout << "j'ai une collision ? " << distance << std::endl;
        if (distance != -1) {
            this->_color = list[position]->getColor(this->_ray, this->_displayable);
            std::cout << "color catch : " << this->_color << std::endl;
        }
    }
}
