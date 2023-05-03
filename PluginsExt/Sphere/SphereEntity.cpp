/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereEntity.cpp
*/

#include <algorithm>
#include <cmath>
#include <optional>
#include "ISetting.hpp"
#include "SphereEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Sphere {
    SphereEntity::SphereEntity(const Scenes::ISetting &config):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _material(*config.get("material")),
        _radius(static_cast<double>(*config.get("radius")))
    {
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
        auto a = ray.getDirection().dot(ray.getDirection());
        auto b = (Entities::Transform::Vector3f(2, 2, 2) * ray.getDirection()).dot(ray.getOrigin() - _transform.getPosition());
        auto c = (ray.getOrigin() - _transform.getPosition()).dot(ray.getOrigin() - _transform.getPosition()) - (_radius * _radius);
        auto discriminant = (b * b) - (4 * a * c);

        if (discriminant < 0) {
            return std::nullopt;
        }
        auto t = (-b - std::sqrt(discriminant)) / (2 * a);
        if (t <= 0) {
            t = (-b + std::sqrt(discriminant)) / (2 * a);
            if (t <= 0) {
                return std::nullopt;
            }
        }
        std::cout << t << "!collision!" << std::endl;
        return std::make_optional(Entities::Transform::Vector3f(ray.getOrigin() + (ray.getDirection() * Entities::Transform::Vector3f(t, t, t))));
    }

    Images::Color SphereEntity::getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const
    {
        auto intersect = isCollided(ray);
        return _material.getColor(ray, _transform, intersect.value(), displayable);
    }
}
