/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** LimitedPlaneEntity.cpp
*/

#include "ILogger.hpp"
#include "LimitedPlaneEntity.hpp"
#include "IMaterialFactory.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::LimitedPlane {
    LimitedPlaneEntity::LimitedPlaneEntity(const Scenes::ISetting &config, ILogger &logger):
            _transform(Entities::Transform::Transform(*config.get("transform"))),
            _size(Entities::Transform::Vector2i(*config.get("size"))),
            _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        if (_transform.getScale().getZ() != 0) {
            _logger.warn("PLANE: config: scale z must be 0 (remainder: x is for size x, y is for size y");
        }
        _size = _size * Entities::Transform::Vector2i(_transform.getScale().getX(), _transform.getScale().getY());
    }

    Entities::IEntity::Type LimitedPlaneEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &LimitedPlaneEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &LimitedPlaneEntity::getTransform() const {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> LimitedPlaneEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rotation = this->getTransform().getRotation();
        const Entities::Transform::Vector3f &point = this->getTransform().getPosition();
        Entities::Transform::Vector3f normal = this->getTransform().getRotation();
        float d = -(normal.getX() * point.getX() + normal.getY() * point.getY() + normal.getZ() * point.getZ());
        const Entities::Transform::Vector3f &direction = ray.getDirection();
        const Entities::Transform::Vector3f &startPoint = ray.getOrigin();
        float t = -(normal.getX() * startPoint.getX() + normal.getY() * startPoint.getY() + normal.getZ() * startPoint.getZ() + d)
                  / (normal.getX() * direction.getX() + normal.getY() * direction.getY() + normal.getZ() * direction.getZ());
        double sizeY = _size.getX() > _size.getY() ? _size.getX() : _size.getY();

        if (t >= 0 && t <= 400) {
            Entities::Transform::Vector3f collisionPoint = startPoint + direction * Entities::Transform::Vector3f(t, t, t);
            if (std::abs(collisionPoint.getX() - _transform.getPosition().getX()) < _size.getX() / 2.0 &&
                std::abs(collisionPoint.getZ() - _transform.getPosition().getZ())  < _size.getY() / 2.0 &&
                std::abs(collisionPoint.getY() - _transform.getPosition().getY()) <  sizeY / 2)
                return collisionPoint;
        }
        return std::nullopt;
    }

    bool LimitedPlaneEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color LimitedPlaneEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        auto transform = _transform;
        auto pos = intersect - _transform.getRotation();
        transform.setPosition(pos);
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color LimitedPlaneEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
