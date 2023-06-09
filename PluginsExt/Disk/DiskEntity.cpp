/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntity.cpp
*/

#include <cmath>
#include "ILogger.hpp"
#include "IMaterialFactory.hpp"
#include "DiskEntity.hpp"

namespace RayTracer::PluginsExt::Disk {
    DiskEntity::DiskEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _radius(*config.get("radius")),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        if (_transform.getScale().getY() != 0 || _transform.getScale().getZ() != 0) {
            _logger.warn("DISK: config: scale y z must be 0: (remainder: x is for radius)");
        }
        _radius = std::abs(_radius * _transform.getScale().getX());
    }

    Entities::IEntity::Type DiskEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &DiskEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &DiskEntity::getTransform() const {
        return this->_transform;
    }

    std::optional <Entities::Transform::Vector3f> DiskEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rotation = this->getTransform().getRotation();
        const Entities::Transform::Vector3f &point = this->getTransform().getPosition();
        Entities::Transform::Vector3f normal = this->getTransform().getRotation();
        float d = -(normal.getX() * point.getX() + normal.getY() * point.getY() + normal.getZ() * point.getZ());
        const Entities::Transform::Vector3f &direction = ray.getDirection();
        const Entities::Transform::Vector3f &startPoint = ray.getOrigin();
        float t = -(normal.getX() * startPoint.getX() + normal.getY() * startPoint.getY() + normal.getZ() * startPoint.getZ() + d)
                  / (normal.getX() * direction.getX() + normal.getY() * direction.getY() + normal.getZ() * direction.getZ());

        if (t >= 0 && t <= 400) {
            Entities::Transform::Vector3f collisionPoint = startPoint + direction * Entities::Transform::Vector3f(t, t, t);
            if (collisionPoint.getDistance(point) <= this->_radius)
                return collisionPoint;
        }
        return std::nullopt;
    }

    bool DiskEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color DiskEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
    const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        auto pos = intersect - _transform.getRotation();
        transform.setPosition(pos);
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color DiskEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
    const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
