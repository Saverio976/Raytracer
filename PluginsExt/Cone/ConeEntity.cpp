/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeEntity.cpp
*/

#include "ConeEntity.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Cone {
    ConeEntity::ConeEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _angle(static_cast<double>(*config.get("angle"))),
        _logger(logger)
    {
    }

    Entities::IEntity::Type ConeEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &ConeEntity::getTransform()
    {
        return this->_transform;
    }

    const Entities::Transform::ITransform &ConeEntity::getTransform() const
    {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> ConeEntity::isCollided(const Images::Ray &ray) const
    {
        Entities::Transform::Vector3f coneStart = _transform.getPosition();
        Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f &rayStart = ray.getOrigin();
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        Entities::Transform::Vector3f deltaP(rayStart.getX() - coneStart.getX(), rayStart.getY() - coneStart.getY(), rayStart.getZ() - coneStart.getZ());

        double vDeltaPValue = rayDirection.dot(deltaP);
        Entities::Transform::Vector3f collision(0, 0, 0);

        double a = (pow(cos(_angle), 2)) * (rayDirection.getX() * rayDirection.getX() + rayDirection.getY() * rayDirection.getY() + rayDirection.getZ() * rayDirection.getZ()) -
                (coneDirection.getX() * coneDirection.getX() + coneDirection.getY() * coneDirection.getY() + coneDirection.getZ() * coneDirection.getZ());
        double b = 2 * pow(cos(_angle), 2) * vDeltaPValue -
                2 * (coneDirection.dot(rayDirection * deltaP) * coneDirection.getX() + coneDirection.dot(rayDirection * deltaP) * coneDirection.getY() + coneDirection.dot(rayDirection * deltaP) * coneDirection.getZ());
        double c = pow(cos(_angle), 2) * (deltaP.getX() * deltaP.getX() + deltaP.getY() * deltaP.getY() + deltaP.getZ() * deltaP.getZ()) - pow(deltaP.dot(coneDirection), 2);
        double delta = pow(b, 2) - 4 * a * c;

        std::cout << _angle << std::endl;

        if (delta < 0) {
            return std::nullopt;
        } else if (delta > 0) {
            double t1 = ((-1 * b + sqrt(delta)) / (2 * a));
            double t2 = ((-1 * b - sqrt(delta)) / (2 * a));
            double t = t1 > t2 ? t2 : t1;

            collision = rayStart + rayDirection * Entities::Transform::Vector3f(t, t, t);
        } else {
            double t = -1 * b / (2 * a);

            collision = rayStart + rayDirection * Entities::Transform::Vector3f(t, t, t);
        }

        return collision;
    }

    bool ConeEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    Images::Color ConeEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable, const Entities::Transform::Vector3f &point) const
    {
        return {255, 0, 0, 255};
    }
}
