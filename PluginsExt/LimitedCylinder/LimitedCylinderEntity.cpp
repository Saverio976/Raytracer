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
        if (_transform.getScale().getZ() != 0) {
            _logger.warn("LIMITED_CYLINDER: config: scale z must be 0 (remainder: x is for radius, z is for height)");
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

    std::optional<Entities::Transform::Vector3f> LimitedCylinderEntity::isCollided(const Images::Ray &ray) const {
        Entities::Transform::Vector3f oc = ray.getOrigin() - this->_transform.getPosition();
        double a = std::pow(ray.getDirection().getX(), 2) + std::pow(ray.getDirection().getY(), 2);
        double b = 2 * (oc.getX() * ray.getDirection().getX() + oc.getY() * ray.getDirection().getY());
        double c = std::pow(oc.getX(), 2) + std::pow(oc.getY(), 2) - std::pow(_radius, 2);

        double discriminant = std::pow(b, 2) - 4 * a * c;

        if (discriminant < 0)
            return std::nullopt;
        double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
        double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

        double z1 = oc.getZ() + t1 * ray.getDirection().getZ();
        double z2 = oc.getZ() + t2 * ray.getDirection().getZ();

        if ((z1 >= 0 && z1 <= _height) || (z2 >= 0 && z2 <= _height)) {
            Entities::Transform::Vector3f collisionPoint = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t1, t1, t1);
            return collisionPoint;
        }
        return std::nullopt;
    }

    Images::Color LimitedCylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        Entities::Transform::Vector3f origin = this->_transform.getPosition();
        transform.setPosition(Entities::Transform::Vector3f(origin.getX(), origin.getY(), intersect.getZ()));
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color LimitedCylinderEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
