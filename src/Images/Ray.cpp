/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray.cpp
*/

#include <cmath>
#include "Vector3f.hpp"
#include "Ray.hpp"

namespace RayTracer::Images {
    Ray::Ray(const Entities::Transform::Vector3f &startCamera, const Entities::Transform::Vector3f &screenPos):
        _origin(screenPos), _normal(0, 0, 0), _step(screenPos)
    {
        _normal = screenPos - startCamera;
    }

    const Entities::Transform::Vector3f &Ray::getOrigin() const
    {
        return _origin;
    }

    const Entities::Transform::Vector3f &Ray::getDirection() const
    {
        return _normal;
    }

    const Entities::Transform::Vector3f &Ray::getStep() const
    {
        return _step;
    }

    void Ray::operator+=(double t)
    {
        Entities::Transform::Vector3f tVector(t, t, t);
        _step = _step + (tVector * _normal);
    }

    void Ray::operator-=(double t)
    {
        Entities::Transform::Vector3f tVector(t, t, t);
        _step = _step - (tVector * _normal);
    }

    Ray &Ray::operator++()
    {
        _step = _step + _normal;
        return *this;
    }

    Ray &Ray::operator--()
    {
        _step = _step - _normal;
        return *this;
    }
}
