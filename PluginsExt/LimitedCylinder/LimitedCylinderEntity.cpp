/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderEntity.cpp
*/

#include <array>
#include <cmath>
#include <exception>
#include <iostream>
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
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::LimitedCylinder {
    LimitedCylinderEntity::LimitedCylinderEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(*config.get("transform")),
        _direction(_transform.getRotation()),
        _radius(*config.get("radius")),
        _logger(logger),
        _height(*config.get("height"))
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        _direction = _transform.getRotation().getNormalized();
        if (_transform.getScale().getZ() != 0) {
            _logger.warn("LIMITED_CYLINDER: config: scale z must be 0 (remainder: x is for radius, z is for height)");
        }
        if (_transform.getRotation().getX() != 0 || _transform.getRotation().getY() != 0 || _transform.getRotation().getZ() != 0) {
            _logger.warn("CYLINDER: config: rotation x y z must be 0 (rotation not supported)");
        }
        _radius = std::abs(_radius * _transform.getScale().getX());
        _height = std::abs(_height * _transform.getScale().getY());
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

    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollided(const Images::Ray &ray) const
    {
        std::array<double, 8> args = {
            1,
            ray.getOrigin().getX() - _transform.getPosition().getX(),
            ray.getOrigin().getY() - _transform.getPosition().getY(),
            ray.getOrigin().getZ() - _transform.getPosition().getZ(),
            ray.getDirection().getX(), ray.getDirection().getY(), ray.getDirection().getZ(),
            _radius
        };
        double a = args[4] * args[4] + args[5] * args[5];
        double b = 2.0 * (args[1] * args[4] + args[2] * args[5]);
        double c = args[1] * args[1] + args[2] * args[2] - args[7] * args[7];
        double delta = b * b - 4 * a * c;

        if (delta < 0 || std::abs(delta) < 0.001) {
            return std::nullopt;
        }
        double t1 = (-b - std::sqrt(delta)) / (2 * a);
        auto m1 = ray.getDirection().dot(_direction) * t1 + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        auto vec1 = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t1, t1, t1);
        double t2 = (-b + std::sqrt(delta)) / (2 * a);
        auto m2 = ray.getDirection().dot(_direction) * t1 + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        auto vec2 = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t2, t2, t2);
        if (ray.getOrigin().getDistance(vec1) < ray.getOrigin().getDistance(vec2)) {
            if (m1 > 0 && _transform.getPosition().getDistance(vec1) < _height) {
                return vec1;
            }
            if (m2 > 0 && _transform.getPosition().getDistance(vec2) < _height) {
                return vec2;
            }
            return std::nullopt;
        } else {
            if (m2 > 0 && _transform.getPosition().getDistance(vec2) < _height) {
                return vec2;
            }
            if (m1 > 0 && _transform.getPosition().getDistance(vec1) < _height) {
                return vec1;
            }
            return std::nullopt;
        }
    }

    Images::Color LimitedCylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        std::array<double, 8> args = {
            1,
            ray.getOrigin().getX() - _transform.getPosition().getX(),
            ray.getOrigin().getY() - _transform.getPosition().getY(),
            ray.getOrigin().getZ() - _transform.getPosition().getZ(),
            ray.getDirection().getX(), ray.getDirection().getY(), ray.getDirection().getZ(),
            _radius
        };
        double a = args[4] * args[4] + args[5] * args[5];
        double b = 2.0 * (args[1] * args[4] + args[2] * args[5]);
        double c = args[1] * args[1] + args[2] * args[2] - args[7] * args[7];
        double delta = b * b - 4 * a * c;
        double t1 = (-b - std::sqrt(delta)) / (2 * a);
        auto m1 = ray.getDirection().dot(_direction) * t1 + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        auto vec1 = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t1, t1, t1);
        double t2 = (-b + std::sqrt(delta)) / (2 * a);
        auto m2 = ray.getDirection().dot(_direction) * t1 + (ray.getOrigin() - _transform.getPosition()).dot(_direction);
        auto vec2 = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t2, t2, t2);
        double m;
        if (ray.getOrigin().getDistance(vec1) < ray.getOrigin().getDistance(vec2)) {
            m = m1;
        } else {
            m = t2;
        }

        auto transform = _transform;
        auto aa = _transform.getPosition() + (_direction * Entities::Transform::Vector3f(m, m, m));
        transform.setPosition(aa);
        return _material->get().getColor(ray, _transform, intersect, displayable);
    }

    Images::Color LimitedCylinderEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
