/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SpotLightEntity.cpp
*/

#include <cmath>
#include "SpotLightEntity.hpp"
#include "ILogger.hpp"
#include "Ray.hpp"
#include "IPrimitive.hpp"

namespace RayTracer::PluginsExt::SpotLight {
    SpotLightEntity::SpotLightEntity(const Scenes::ISetting &config, ILogger &logger):
            _transform(Entities::Transform::Transform(*config.get("transform"))),
            _color(*config.get("color")),
            _power(*config.get("power")),
            _radius(*config.get("radius")),
            _angle(*config.get("angle")),
            _logger(logger)
    {
    }

    Entities::Transform::ITransform &SpotLightEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &SpotLightEntity::getTransform() const {
        return this->_transform;
    }

    Entities::IEntity::Type SpotLightEntity::getType() const {
        return Type::Light;
    }

    const Images::Color &SpotLightEntity::getColor() const {
        return this->_color;
    }

    Images::Color SpotLightEntity::getColor(const Entities::Transform::Vector3f &point,
    const Scenes::IDisplayable &displayable) const {
        Entities::Transform::Vector3f normal = (this->_transform.getPosition() - point).getNormalized();
        Entities::Transform::Vector3f vector = point + normal;
        Images::Ray ray(point, vector);
        std::optional<Entities::Transform::Vector3f> impact;
        double distance = point.getDistance(this->_transform.getPosition());
        double tmpDistance = 0;
        Images::Color result(this->_color);
        double angle = this->_transform.getPosition().getAngle(
            this->_transform.getPosition() + this->_transform.getRotation(),
            point
        );

        if (angle < 180 - this->_angle)
            return {0, 0, 0, 0};
        for (const std::reference_wrapper<Entities::IPrimitive> &primitive : displayable.getPrimitiveList()) {
            impact = primitive.get().isCollided(ray);
            if (impact == std::nullopt)
                continue;
            tmpDistance = impact->getDistance(this->_transform.getPosition());
            if (tmpDistance >= distance)
                continue;
            return primitive.get().redirectionLight(ray, displayable, *impact);
        }
        result.applyDistance(distance, this->_radius);
        return result;
    }

    void SpotLightEntity::setColor(const Images::Color &color) {
        this->_color = color;
    }

    bool SpotLightEntity::isAmbient() const
    {
        return false;
    }

    double SpotLightEntity::getPower() const {
        return this->_power;
    }
}
