/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderEntity.cpp
*/

#include <array>
#include <cmath>
#include <exception>
#include <map>
#include <optional>
#include <vector>
#include "LimitedCylinderCreator.hpp"
#include "LimitedCylinderEntity.hpp"
#include "IEntity.hpp"
#include "Ray.hpp"
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

    std::array<double, 2> LimitedCylinderEntity::isCollidedInfiniteCylinder(const Images::Ray &ray) const
    {
        double a = (_direction.getX() * _direction.getX()) + (_direction.getY() * _direction.getY()) + (_direction.getZ() * _direction.getZ());
        double b = 2 * (_direction.getX() * ray.getOrigin().getX()) + 2 * (_direction.getY() * ray.getOrigin().getY()) + 2 * (_direction.getZ() * ray.getOrigin().getZ());
        double c = (ray.getOrigin().getX() * ray.getOrigin().getX()) + (ray.getOrigin().getZ() * ray.getOrigin().getY()) + (ray.getOrigin().getZ() * ray.getOrigin().getZ()) - (_radius * _radius);
        double delta = b * b - 4 * a * c;

        if (delta < 0 || std::abs(delta) < 0.001) {
            return {-1, -1};
        }
        double t = (-b - std::sqrt(delta)) / (2 * a);
        double t2 = (-b + std::sqrt(delta)) / (2 * a);
        return {t, t2};
    }

    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollided(const Images::Ray &ray) const
    {
        auto tt = isCollidedInfiniteCylinder(ray);

        if (tt[0] < 0 && tt[1] < 0) {
            return std::nullopt;
        }
        auto t = tt[0];
        auto m = ray.getDirection().dot(_direction) * t + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        Entities::Transform::Vector3f intersect = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
        auto aa = intersect - _transform.getPosition() - (_direction * Entities::Transform::Vector3f(m, m, m));
        auto bb = aa.dot(_direction);
        if (std::abs(bb) < 0.001 && m > 0 && _transform.getPosition().getDistance(aa) < _height) {
            return intersect;
        }
        t = tt[1];
        m = ray.getDirection().dot(_direction) * t + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        intersect = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
        aa = intersect - _transform.getPosition() - (_direction * Entities::Transform::Vector3f(m, m, m));
        bb = aa.dot(_direction);
        if (std::abs(bb) < 0.001 && m > 0 && _transform.getPosition().getDistance(aa) < _height) {
            return intersect;
        }
        return std::nullopt;
    }

    /* This work
    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollided(const Images::Ray &ray) const
    {
        auto tt = isCollidedInfiniteCylinder(ray);

        if (tt[0] < 0 && tt[1] < 0) {
            return std::nullopt;
        }
        auto t = tt[0];
        auto m = ray.getDirection().dot(_direction) * t + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        Entities::Transform::Vector3f intersect = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
        auto aa = intersect - _transform.getPosition() - (_direction * Entities::Transform::Vector3f(m, m, m));
        auto bb = aa.dot(_direction);
        if (std::abs(bb) > 0.001) {
            t = tt[1];
            m = ray.getDirection().dot(_direction) * t + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
            intersect = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
            aa = intersect - _transform.getPosition() - (_direction * Entities::Transform::Vector3f(m, m, m));
            bb = aa.dot(_direction);
            if (std::abs(bb) > 0.001) {
                return std::nullopt;
            }
        }
        return intersect;
    }
     */

    Images::Color LimitedCylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        auto tt = isCollidedInfiniteCylinder(ray);
        auto m = ray.getDirection().dot(_direction) * tt[0] + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        auto aa = intersect - _transform.getPosition() - (_direction * Entities::Transform::Vector3f(m, m, m));
        transform.setPosition(aa);
        return _material.getColor(ray, transform, intersect, displayable);
    }
}
