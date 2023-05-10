/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedConeEntity.cpp
*/

#include "LimitedConeEntity.hpp"
#include "ILogger.hpp"
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::LimitedCone {
    LimitedConeEntity::LimitedConeEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _angle(static_cast<double>(*config.get("angle"))),
        _logger(logger),
        _height(*config.get("height"))
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

    Entities::IEntity::Type LimitedConeEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &LimitedConeEntity::getTransform()
    {
        return this->_transform;
    }

    const Entities::Transform::ITransform &LimitedConeEntity::getTransform() const
    {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> LimitedConeEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f coneOrigin = _transform.getPosition();
        const Entities::Transform::Vector3f rayToConeOrigin(rayOrigin.getX() - coneOrigin.getX(),rayOrigin.getY() - coneOrigin.getY(),rayOrigin.getZ() - coneOrigin.getZ());
        double testAngle = pow(tan(_angle), 2);

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

            if (t1 > t2)
                std::swap(t1, t2);
            if (t1 > 0) {
                collision = rayOrigin + rayDirection * Entities::Transform::Vector3f(t1, t1, t1);
                double distance = sqrt(
                        pow(collision.getX() - coneOrigin.getX(), 2) + pow(collision.getY() - coneOrigin.getY(), 2) +
                        pow(collision.getZ() - coneOrigin.getZ(), 2));
                if (distance < _height) {
                    Entities::Transform::Vector3f remove(collision.getX() - coneOrigin.getX(),collision.getY() - coneOrigin.getY(),collision.getZ() - coneOrigin.getZ());
                    if (remove.dot(coneDirection) > 0)
                        return collision;
                }
            }
        }
        return std::nullopt;
    }

    bool LimitedConeEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    Images::Color LimitedConeEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable, const Entities::Transform::Vector3f &point) const
    {
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f coneDirection = _transform.getRotation();
        const Entities::Transform::Vector3f coneOrigin = _transform.getPosition();
        const Entities::Transform::Vector3f rayToConeOrigin(rayOrigin.getX() - coneOrigin.getX(),rayOrigin.getY() - coneOrigin.getY(),rayOrigin.getZ() - coneOrigin.getZ());
        double testAngle = pow(tan(_angle), 2);

        double a = pow(rayDirection.dot(coneDirection), 2) - testAngle * rayDirection.dot(rayDirection);
        double b = 2 * (rayToConeOrigin.dot(coneDirection) * rayDirection.dot(coneDirection) - testAngle * rayToConeOrigin.dot(rayDirection));
        double c = pow(rayToConeOrigin.dot(coneDirection), 2) - testAngle * rayToConeOrigin.dot(rayToConeOrigin);
        double delta = (b * b) - (4 * a * c);
        double t = (-b - std::sqrt(delta)) / (2 * a);

        auto transform = _transform;
        auto m = ray.getDirection().dot(coneDirection) * t + (ray.getOrigin() - _transform.getPosition()).dot(coneDirection);
        auto aa = point - _transform.getPosition() - (coneDirection * Entities::Transform::Vector3f(m, m, m));
        transform.setPosition(aa);
        return _material->get().getColor(ray, _transform, point, displayable);
    }

    Images::Color LimitedConeEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
