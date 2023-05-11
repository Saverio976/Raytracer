/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CylinderEntity.cpp
*/

#include <cmath>
#include "CylinderCreator.hpp"
#include "CylinderEntity.hpp"
#include "IEntity.hpp"
#include "Transform.hpp"
#include "ISetting.hpp"
#include "ILogger.hpp"
#include "Vector3f.hpp"
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::Cylinder {
    CylinderEntity::CylinderEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(*config.get("transform")),
        _radius(*config.get("radius")),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        _direction = _transform.getRotation();
        if (_transform.getScale().getY() != 0 || _transform.getScale().getZ() != 0) {
            _logger.warn("CYLINDER: config: scale y z must be 0 (remainder: x is for radius");
        }
        _radius = std::abs(_radius * _transform.getScale().getX());
    }

    Entities::IEntity::Type CylinderEntity::getType() const
    {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &CylinderEntity::getTransform()
    {
        return _transform;
    }

    const Entities::Transform::ITransform &CylinderEntity::getTransform() const
    {
        return _transform;
    }

    bool CylinderEntity::isCollided(const Entities::Transform::Vector3f &point) const
    {
        return false;
    }

    std::optional<Entities::Transform::Vector3f> CylinderEntity::isCollided(const Images::Ray &ray) const
    {
        Entities::Transform::Vector3f oc = ray.getOrigin() - this->_transform.getPosition();
        double a = std::pow(ray.getDirection().getX(), 2) + std::pow(ray.getDirection().getY(), 2);
        double b = 2 * (oc.getX() * ray.getDirection().getX() + oc.getY() * ray.getDirection().getY());
        double c = std::pow(oc.getX(), 2) + std::pow(oc.getY(), 2) - std::pow(_radius, 2);

        double discriminant = std::pow(b, 2) - 4 * a * c;

        if (discriminant < 0)
            return std::nullopt;
        double t1 = (-b - std::sqrt(discriminant)) / (2 * a);

        Entities::Transform::Vector3f collisionPoint = ray.getOrigin() + ray.getDirection() * Entities::Transform::Vector3f(t1, t1, t1);
        return collisionPoint;
    }

    Images::Color CylinderEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        Entities::Transform::Vector3f origin = this->_transform.getPosition();
        transform.setPosition(Entities::Transform::Vector3f(origin.getX(), origin.getY(), intersect.getZ()));
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color CylinderEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
