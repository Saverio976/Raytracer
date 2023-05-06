/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CylinderEntity.cpp
*/

#include "CylinderCreator.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "ISetting.hpp"
#include "ILogger.hpp"
#include "Vector3f.hpp"
#include <cmath>

namespace RayTracer::PluginsExt::Cylinder {
    CylinderEntity::CylinderEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(*config.get("transform")),
        _direction(*config.get("direction")),
        _radius(*config.get("radius")),
        _logger(logger),
        _material(*config.get("material"))
    {
    }

    Entities::IEntity::Type CylinderEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &CylinderEntity::getTransform()
    {
        return _transform;
    }

    const Entities::Transform::ITransform &CylinderEntity::getTransform() const
    {
        return _transform;
    }

    bool CylinderEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    std::optional<Entities::Transform::Vector3f> CylinderEntity::isCollided(const Images::Ray &ray) const
    {
        double a = (_direction.getX() * _direction.getX()) + (_direction.getY() * _direction.getY()) + (_direction.getZ() * _direction.getZ());
        double b = 2 * (_direction.getX() * ray.getOrigin().getX()) + 2 * (_direction.getY() * ray.getOrigin().getY()) + 2 * (_direction.getZ() * ray.getOrigin().getZ());
        double c = (ray.getOrigin().getX() * ray.getOrigin().getX()) + (ray.getOrigin().getZ() * ray.getOrigin().getY()) + (ray.getOrigin().getZ() * ray.getOrigin().getZ()) - (_radius * _radius);
        double delta = b * b - 4 * a * c;
        if (delta < 0 || std::abs(delta) < 0.001) {
            return std::nullopt;
        }
        double t = (-b - std::sqrt(delta)) / (2 * a);
        return ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
    }

    Images::Color CylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        return _material.getColor(ray, _transform, intersect, displayable);
    }
}
