/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeEntity.cpp
*/

#include "ConeEntity.hpp"
#include "ILogger.hpp"
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::Cone {
    ConeEntity::ConeEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _angle(static_cast<double>(*config.get("angle"))),
        _logger(logger),
        _color(*config.get("color"))
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        if (_transform.getScale().getX() != _transform.getScale().getY() ||
                _transform.getScale().getX() != _transform.getScale().getZ()) {
            _logger.warn("CONE: config: scale x y z must be the same: now using only x");
        }
        _angle = _angle * _transform.getScale().getX();
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
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f coneOrigin = _transform.getPosition();
        const Entities::Transform::Vector3f rayToConeOrigin(rayOrigin.getX() - coneOrigin.getX(), rayOrigin.getY() - coneOrigin.getY(), rayOrigin.getZ() - coneOrigin.getZ());

        double testAngle = pow(-0.4777070063694 * _angle + 1.5, 2);

        double a = pow(rayDirection.dot(coneDirection), 2) - testAngle * rayDirection.dot(rayDirection);
        double b = 2 * (rayToConeOrigin.dot(coneDirection) * rayDirection.dot(coneDirection) - testAngle * rayToConeOrigin.dot(rayDirection));
        double c = pow(rayToConeOrigin.dot(coneDirection), 2) - testAngle * rayToConeOrigin.dot(rayToConeOrigin);
        double delta = (b * b) - (4 * a * c);

        Entities::Transform::Vector3f collision(0, 0, 0);
        if (delta < 0) {
            return std::nullopt;
        } else {
            double t1 = ((-1 * b) + sqrt(delta)) / (2 * a);
            double t2 = ((-1 * b) - sqrt(delta)) / (2 * a);

            double t = -1;
            if (t1 > 0 && t2 > 0) {
                t = std::min(t1, t2);
            } else if (t1 > 0) {
                t = t1;
            } else if (t2 > 0) {
                t = t2;
            }
            if (t > 0) {
                collision = rayOrigin + rayDirection * Entities::Transform::Vector3f(t, t, t);
                return collision;
            } else {
                return std::nullopt;
            }
        }
    }

    bool ConeEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    Images::Color ConeEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable, const Entities::Transform::Vector3f &point) const
    {
        return _color;
    }

    Images::Color ConeEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
