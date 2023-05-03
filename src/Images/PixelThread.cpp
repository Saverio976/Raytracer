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

        std::cout << "je passes pour le calcul du pixel " << _ray.getOrigin().getX() << " " << _ray.getOrigin().getY() << " " << _ray.getOrigin().getZ() << std::endl; 
        for (size_t i = 0; i < list.size(); i++) {
            point = list[i]->isCollided(this->_ray);
            if (point == std::nullopt) {
                std::cout << "pas de collision" << std::endl;
                continue;
            }
            std::cout << point->getX() << " " << point->getY() << " " << point->getZ() <<std::endl;
            std::cout << "!!!!!!!!!!collision!!!!!!!!!!" << std::endl;
            tmpDistance = point->getDistance(this->_ray.getOrigin());
            if (tmpDistance < distance || distance == -1) {
                distance = tmpDistance;
                position = i;
            }
        }
        if (distance != -1) {
            this->_color = list[position]->getColor(this->_ray, this->_displayable);
            std::cout << "color catch : " << this->_color << std::endl;
        }
    }
}
