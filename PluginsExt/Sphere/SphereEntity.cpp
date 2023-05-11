/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereEntity.cpp
*/

#include <algorithm>
#include <cmath>
#include <optional>
#include <utility>
#include "Color.hpp"
#include "ILogger.hpp"
#include "ISetting.hpp"
#include "SphereEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"
#include "IDisplayable.hpp"
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::Sphere {
    SphereEntity::SphereEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _radius(static_cast<double>(*config.get("radius"))),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        if (_transform.getScale().getY() != 0 || _transform.getScale().getZ() != 0) {
            _logger.warn("SPHERE: config: scale y z must be 0 (remainder: x is for radius)");
        }
        if (_transform.getRotation().getY() != 0 || _transform.getRotation().getZ() != 0 || _transform.getRotation().getX() != 0) {
            _logger.warn("SPHERE: config: rotation x y z must be 0 (why rotate a sphere ?)");
        }
        _radius = std::abs(_radius * _transform.getScale().getX());
    }

    Entities::IEntity::Type SphereEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &SphereEntity::getTransform()
    {
        return _transform;
    }

    const Entities::Transform::ITransform &SphereEntity::getTransform() const
    {
        return _transform;
    }

    bool SphereEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    std::optional<Entities::Transform::Vector3f> SphereEntity::isCollided(const Images::Ray &ray) const
    {
        long double a = ray.getDirection().dot(ray.getDirection());
        long double b = (Entities::Transform::Vector3f(2, 2, 2) * ray.getDirection()).dot(ray.getOrigin() - _transform.getPosition());
        long double c = (ray.getOrigin() - _transform.getPosition()).dot(ray.getOrigin() - _transform.getPosition()) - (_radius * _radius);
        long double discriminant = (b * b) - (4 * a * c);
        long double precision = 0;

        if (discriminant < precision) {
            return std::nullopt;
        }
        long double t = (-b - std::sqrt(discriminant)) / (2 * a);
        if (t <= precision) {
            t = (-b + std::sqrt(discriminant)) / (2 * a);
            if (t <= precision) {
                return std::nullopt;
            }
        }
        auto vect = Entities::Transform::Vector3f(ray.getOrigin() + (ray.getDirection() * Entities::Transform::Vector3f(t, t, t)));;
        return std::make_optional(vect);
    }

    Images::Color SphereEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().getColor(ray, _transform, intersect, displayable) + Images::Color(0, 0, 0, 255);
    }

    Images::Color SphereEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
