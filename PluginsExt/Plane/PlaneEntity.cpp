/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntity.cpp
*/

#include <cmath>
#include "PlaneEntity.hpp"

namespace RayTracer::PluginsExt::Plane {
    PlaneEntity::PlaneEntity(const Scenes::ISetting &config):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _size(Entities::Transform::Vector3f(*config.get("size"))),
        _material(*config.get("material")) { }

    Entities::IEntity::Type PlaneEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &PlaneEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &PlaneEntity::getTransform() const {
        return this->_transform;
    }

    std::optional <Entities::Transform::Vector3f> PlaneEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rotation = this->getTransform().getRotation();
        Entities::Transform::Vector3f normal(
                std::sin(rotation.getX()) * std::sin(rotation.getY()),
                std::sin(rotation.getX()) * std::cos(rotation.getY()),
                std::cos(rotation.getX())
        );
        Entities::Transform::Vector3f direction = ray.getDirection();
        float denom = normal.dot(direction);

        if (denom > 1e-6) {
            Entities::Transform::Vector3f origin = getTransform().getPosition() - ray.getOrigin();
            float t = origin.dot(normal) / denom;
            if (t >= 0) {
                Entities::Transform::Vector3f collision = ray.getOrigin() + direction * Entities::Transform::Vector3f(t, t, t);
                return collision;
            }
        }
        return std::nullopt;
    }

    bool PlaneEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color PlaneEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
    const Entities::Transform::Vector3f &intersect) const
    {
        return _material.getColor(ray, _transform, intersect, displayable);
    }
}
