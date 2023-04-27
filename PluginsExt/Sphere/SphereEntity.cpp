/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereEntity.cpp
*/

#include "SphereEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"
#include <cmath>

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

    bool SphereEntity::isCollided(const Images::Ray &ray) const
    {
        Entities::Transform::Vector3f oc = ray.getOrigin() - _transform.getPosition();
        auto a = ray.getDirection().dot(ray.getDirection());
        auto b = 2.0 * oc.dot(ray.getDirection());
        auto c = oc.dot(oc) - std::pow(_radius, 2);
        auto discriminant = std::pow(b, 2) - (4 * a * c);

        return (discriminant > 0);
    }
}
