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
        _size(Entities::Transform::Vector3f(*config.get("size"))) { }

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
        const Entities::Transform::Vector3f &point = this->getTransform().getPosition();
        Entities::Transform::Vector3f normal(
             std::sin(rotation.getX()) * std::sin(rotation.getZ()),
             std::cos(rotation.getX()),
             std::sin(rotation.getX()) * std::cos(rotation.getZ())
        );
        float d = -(normal.getX() * point.getX() + normal.getY() * point.getY() + normal.getZ() * point.getZ());
        const Entities::Transform::Vector3f &direction = ray.getDirection();
        const Entities::Transform::Vector3f &startPoint = ray.getOrigin();
        float t = -(normal.getX() * startPoint.getX() + normal.getY() * startPoint.getY() + normal.getZ() * startPoint.getZ() + d)
            / (normal.getX() * direction.getX() + normal.getY() * direction.getY() + normal.getZ() * direction.getZ());

        if (t >= 0 && t <= 1) {
            Entities::Transform::Vector3f collisionPoint = startPoint + direction * Entities::Transform::Vector3f(t, t, t);
            if (
                collisionPoint.getX() >= point.getX() - this->_size.getX() / 2 && collisionPoint.getX() <= point.getX() + this->_size.getX() / 2 &&
                collisionPoint.getY() >= point.getY() - this->_size.getY() / 2 && collisionPoint.getY() <= point.getY() + this->_size.getY() / 2 &&
                collisionPoint.getX() >= point.getZ() - this->_size.getZ() / 2 && collisionPoint.getZ() <= point.getZ() + this->_size.getZ() / 2
            ) {
                return collisionPoint;
            }
        }
        return std::nullopt;
    }

    bool PlaneEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color PlaneEntity::getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const {
        return {255, 0, 0, 255};
    }
}