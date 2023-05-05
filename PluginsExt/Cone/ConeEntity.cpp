/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeEntity.cpp
*/

#include "ConeEntity.hpp"

namespace RayTracer::PluginsExt::Cone {
    ConeEntity::ConeEntity(const Scenes::ISetting &config):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _angle(static_cast<double>(*config.get("angle"))) {}

    Entities::IEntity::Type ConeEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &ConeEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &ConeEntity::getTransform() const {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> ConeEntity::isCollided(const Images::Ray &ray) const {
        Entities::Transform::Vector3f coneStart = _transform.getPosition();
        Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f& rayDirection = ray.getDirection();
        const Entities::Transform::Vector3f& rayOrigin = ray.getOrigin();
        Entities::Transform::Vector3f cO = {rayOrigin.getX() - coneStart.getX(), rayOrigin.getY() - coneStart.getY(), rayOrigin.getZ() - coneStart.getZ()};
        Entities::Transform::Vector3f collision(0, 0, 0);

        double a = pow((rayDirection.getX() * coneDirection.getX() + rayDirection.getY() * coneDirection.getY() + rayDirection.getZ() * coneDirection.getZ()), 2) - pow(cos(_angle), 2);
        double b = 2 * ((rayDirection.getX() * coneDirection.getX() + rayDirection.getY() * coneDirection.getY() + rayDirection.getZ() * coneDirection.getZ()) *
                (cO.getX() * coneDirection.getX() + cO.getY() * coneDirection.getY() + cO.getZ() * coneDirection.getZ()) - (rayDirection.getX() * cO.getX() + rayDirection.getY() * cO.getY() + rayDirection.getZ() * cO.getZ())) * pow(cos(_angle), 2);
        double c = (pow((cO.getX() * coneDirection.getX() + cO.getY() * coneDirection.getY() + cO.getZ() * coneDirection.getZ()), 2) - (cO.getX() * cO.getX() + cO.getY() * cO.getY() + cO.getZ() * cO.getZ()) * pow(cos(_angle), 2));
        double delta = pow(b, 2) - 4 * a * c;

        if (delta < 0) {
            return std::nullopt;
        } else if (delta == 0) {
            double t = -b / (2 * a);

            collision = ray.getOrigin() + rayDirection * Entities::Transform::Vector3f(t, t, t);
        } else {
            double t1 = (-b - sqrt(delta)) / (2 * a);

            collision = ray.getOrigin() + rayDirection * Entities::Transform::Vector3f(t1, t1, t1);
        }
        Entities::Transform::Vector3f test(collision.getX() - coneStart.getX(), collision.getY() - coneStart.getY(), collision.getZ() - coneStart.getZ());
        if (coneDirection.dot(test) > 2.44346 )
            return collision;
        return std::nullopt;
    }

    bool ConeEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color ConeEntity::getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const {
        Entities::Transform::Vector3f coneStart = _transform.getPosition();
        Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f& rayDirection = ray.getDirection();
        const Entities::Transform::Vector3f& rayOrigin = ray.getOrigin();
        Entities::Transform::Vector3f cO = {rayOrigin.getX() - coneStart.getX(), rayOrigin.getY() - coneStart.getY(), rayOrigin.getZ() - coneStart.getZ()};
        Entities::Transform::Vector3f collision(0, 0, 0);

        double a = pow((rayDirection.getX() * coneDirection.getX() + rayDirection.getY() * coneDirection.getY() + rayDirection.getZ() * coneDirection.getZ()), 2) - pow(cos(_angle), 2);
        double b = 2 * ((rayDirection.getX() * coneDirection.getX() + rayDirection.getY() * coneDirection.getY() + rayDirection.getZ() * coneDirection.getZ()) *
                        (cO.getX() * coneDirection.getX() + cO.getY() * coneDirection.getY() + cO.getZ() * coneDirection.getZ()) - (rayDirection.getX() * cO.getX() + rayDirection.getY() * cO.getY() + rayDirection.getZ() * cO.getZ())) * pow(cos(_angle), 2);
        double c = (pow((cO.getX() * coneDirection.getX() + cO.getY() * coneDirection.getY() + cO.getZ() * coneDirection.getZ()), 2) - (cO.getX() * cO.getX() + cO.getY() * cO.getY() + cO.getZ() * cO.getZ()) * pow(cos(_angle), 2));
        double delta = pow(b, 2) - 4 * a * c;

        if (delta < 0) {
            return {0, 0, 0, 0};
        } else if (delta == 0) {
            double t = -b / (2 * a);

            collision = ray.getOrigin() + rayDirection * Entities::Transform::Vector3f(t, t, t);
        } else {
            double t1 = (-b - sqrt(delta)) / (2 * a);

            collision = ray.getOrigin() + rayDirection * Entities::Transform::Vector3f(t1, t1, t1);
        }
        Entities::Transform::Vector3f test(collision.getX() - coneStart.getX(), collision.getY() - coneStart.getY(), collision.getZ() - coneStart.getZ());
        if (test.dot(coneDirection) > 2.44346 )
            return {255, 0, 0, 255};
        return {0, 0, 0, 0};
    }
}