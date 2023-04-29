/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereEntity.cpp
*/

#include <cmath>
#include "SphereEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Sphere {
    SphereEntity::SphereEntity(const IConfig &config):
        _transform(Entities::Transform::Transform())
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
        Entities::Transform::Vector3f oc = ray.getOrigin() - _transform.getPosition();
        auto a = ray.getDirection().dot(ray.getDirection());
        auto b = 2.0 * oc.dot(ray.getDirection());
        auto c = oc.dot(oc) - std::pow(_radius, 2);
        auto discriminant = std::pow(b, 2) - (4 * a * c);

        if (discriminant == 0) {
            return std::nullopt;
        }
        auto t = (-b - std::sqrt(discriminant)) / (2 * a);
        auto vect = ray.getDirection() * Entities::Transform::Vector3f(t, t, t);
        vect = vect + ray.getOrigin();
        return std::make_optional(vect);
    }

    Images::Color SphereEntity::getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const
    {
        auto intersect = isCollided(ray);
        return _material.getColor(ray, _transform, intersect.value(), displayable);
    }
}
