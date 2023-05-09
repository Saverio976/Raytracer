/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightEntity.cpp
*/

#include "AmbientLightEntity.hpp"
#include "ILogger.hpp"
#include "Ray.hpp"
#include "IPrimitive.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    AmbientLightEntity::AmbientLightEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _color(*config.get("color")),
        _logger(logger),
        _power(*config.get("power"))
    {
        if (_transform.getScale().getY() != 0 || _transform.getScale().getZ() != 0) {
            _logger.warn("AMBIENT_lIGHT: config: scale y z must be 0 (remainder: x is for power)");
        }
        _power = std::abs(_power * _transform.getScale().getX());
    }

    Entities::Transform::ITransform &AmbientLightEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &AmbientLightEntity::getTransform() const {
        return this->_transform;
    }

    Entities::IEntity::Type AmbientLightEntity::getType() const {
        return Type::Light;
    }

    const Images::Color &AmbientLightEntity::getColor() const {
        return this->_color;
    }

    Images::Color AmbientLightEntity::getColor(const Entities::Transform::Vector3f &point,
    const Scenes::IDisplayable &displayable) const
    {
        Entities::Transform::Vector3f normal = (point - this->_transform.getPosition()).getNormalized();
        Entities::Transform::Vector3f vector = point - normal;
        Images::Ray ray(vector, point);
        std::optional<Entities::Transform::Vector3f> impact;

        return this->_color;
    }

    void AmbientLightEntity::setColor(const Images::Color &color) {
        this->_color = color;
    }

    bool AmbientLightEntity::isAmbient() const
    {
        return true;
    }

    double AmbientLightEntity::getPower() const {
        return this->_power;
    }
}
