/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TorusEntity.cpp
*/

#include <cmath>
#include "ILogger.hpp"
#include "TorusEntity.hpp"
#include "IMaterialFactory.hpp"

namespace RayTracer::PluginsExt::Torus {
    TorusEntity::TorusEntity(const Scenes::ISetting &config, ILogger &logger):
            _transform(Entities::Transform::Transform(*config.get("transform"))),
            _logger(logger),
            _maxRadius(*config.get("maxRadius")),
            _minRadius(*config.get("minRadius"))
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
        if (_transform.getScale().getX() != 0 || _transform.getScale().getY() != 0 || _transform.getScale().getZ() != 0) {
            _logger.warn("PLANE: config: scale x y z must be the 0 (because that's mean nothing to scale an infinite plane)");
        }
    }

    Entities::IEntity::Type TorusEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &TorusEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &TorusEntity::getTransform() const {
        return this->_transform;
    }

    std::optional <Entities::Transform::Vector3f> TorusEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        Entities::Transform::Vector3f torusCenter = _transform.getPosition();

        Entities::Transform::Vector3f oc = rayOrigin - torusCenter;

        double a = rayDirection.dot(rayDirection);
        double b = 2.0 * (oc.dot(rayDirection));
        double c = (oc.dot(oc)) - (_maxRadius * _maxRadius) - (_minRadius * _minRadius) + 2.0 * _maxRadius * sqrt(oc.dot(oc) - _minRadius * _minRadius);
        double d = (b * b) - (4.0 * a * c);

        if (d < 0.0)
            return std::nullopt;
        double t1 = (-b - sqrt(d)) / (2.0 * a);
        double t2 = (-b + sqrt(d)) / (2.0 * a);
        if (t1 < 0.0 && t2 < 0.0) {
            return std::nullopt;
        } else if (t1 < 0.0) {
            return rayOrigin + rayDirection * Entities::Transform::Vector3f(t2, t2, t2);
        } else if (t2 < 0.0) {
            return rayOrigin + rayDirection * Entities::Transform::Vector3f(t1, t1, t1);
        }
        return std::nullopt;
    }

    bool TorusEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color TorusEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        Entities::Transform::Vector3f C = _transform.getPosition();
        Entities::Transform::Vector3f PC = intersect - C;
        double r2 = _minRadius * _minRadius;
        double R2 = _maxRadius * _maxRadius;
        double d = sqrt(PC.getX() * PC.getX() + PC.getY() * PC.getY());
        double nx = PC.getX() * (R2 - r2) / d;
        double ny = PC.getY() * (R2 - r2) / d;
        double nz = PC.getZ() * (R2 + r2 - PC.getX() * PC.getX() - PC.getY() * PC.getY()) / d;
        Entities::Transform::Vector3f normal(nx, ny, nz);
        normal.getNormalized();

        auto transform = _transform;
        auto pos = intersect - normal;
        transform.setPosition(pos);
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color TorusEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
