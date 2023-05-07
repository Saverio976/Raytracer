/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderEntity.cpp
*/

#include <cmath>
#include "LimitedCylinderCreator.hpp"
#include "LimitedCylinderEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "ISetting.hpp"
#include "ILogger.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::LimitedCylinder {
    LimitedCylinderEntity::LimitedCylinderEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(*config.get("transform")),
        _radius(*config.get("radius")),
        _logger(logger),
        _material(*config.get("material")),
        _height(*config.get("height"))
    {
        _transform.setRotation(_transform.getRotation().toRadians());
        _direction = {
            std::sin(_transform.getRotation().getX()) * std::sin(_transform.getRotation().getY()),
            std::sin(_transform.getRotation().getX()) * std::cos(_transform.getRotation().getY()),
            std::cos(_transform.getRotation().getX())
        };
    }

    Entities::IEntity::Type LimitedCylinderEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &LimitedCylinderEntity::getTransform()
    {
        return _transform;
    }

    const Entities::Transform::ITransform &LimitedCylinderEntity::getTransform() const
    {
        return _transform;
    }

    bool LimitedCylinderEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollidedInfiniteCylinder(const Images::Ray &ray) const
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

    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollided(const Images::Ray &ray) const
    {
        auto intersect = isCollidedInfiniteCylinder(ray);

        if (!intersect.has_value()) {
            return std::nullopt;
        }
        auto f = _direction.dot(intersect.value() - _transform.getPosition());
        if (std::abs(f) > 0.001) {
            return std::nullopt;
        }
        auto f2 = std::pow(intersect.value().dot(_transform.getPosition()), 2);
        if (f2 > _radius * _radius) {
            return std::nullopt;
        }
        auto f3 = _direction.dot(intersect.value() - (_transform.getPosition() + _transform.getRotation() * Entities::Transform::Vector3f(_height, _height, _height)));
        if (std::abs(f3) > 0.001) {
            return std::nullopt;
        }
        auto f4 = std::pow(intersect.value().dot(_transform.getPosition() + _transform.getRotation() * Entities::Transform::Vector3f(_height, _height, _height)), 2);
        if (f4 > _radius * _radius) {
            return std::nullopt;
        }
        return intersect;
    }

    Images::Color LimitedCylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        transform.setPosition(intersect * _direction);
        return _material.getColor(ray, _transform, intersect, displayable);
    }
}
