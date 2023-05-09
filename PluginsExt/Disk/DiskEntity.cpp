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
        _rayon(*config.get("rayon")),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
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
            if (collisionPoint.getDistance(point) <= this->_rayon)
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
        return _material->get().getColor(ray, _transform, intersect, displayable);
    }

    Images::Color DiskEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
    const Entities::Transform::Vector3f &intersect) const {
        return {0, 0, 0, 0};
    }
}
