/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightEntity.cpp
*/

#include "PointLightEntity.hpp"
#include "ILogger.hpp"
#include "Ray.hpp"
#include "IPrimitive.hpp"

namespace RayTracer::PluginsExt::PointLight {
    PointLightEntity::PointLightEntity(const Scenes::ISetting &config, ILogger &logger):
            _transform(Entities::Transform::Transform(*config.get("transform"))),
            _color(*config.get("color")),
            _power(*config.get("power")),
            _logger(logger)
    {
    }

    Entities::Transform::ITransform &PointLightEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &PointLightEntity::getTransform() const {
        return this->_transform;
    }

    Entities::IEntity::Type PointLightEntity::getType() const {
        return Type::Light;
    }

    const Images::Color &PointLightEntity::getColor() const {
        return this->_color;
    }

    Images::Color PointLightEntity::getColor(const Entities::Transform::Vector3f &point,
    const Scenes::IDisplayable &displayable) const {
        Entities::Transform::Vector3f normal = (this->_transform.getPosition() - point).getNormalized();
        Entities::Transform::Vector3f vector = point + normal;
        Images::Ray ray(point, vector);
        std::optional<Entities::Transform::Vector3f> impact;
        double distance = point.getDistance(this->_transform.getPosition());
        double tmpDistance = 0;
        Images::Color result(this->_color);
        for (const std::reference_wrapper<Entities::IPrimitive> &primitive : displayable.getPrimitiveList()) {
            impact = primitive.get().isCollided(ray);
            if (impact == std::nullopt)
                continue;
            tmpDistance = impact->getDistance(this->_transform.getPosition());
            if (tmpDistance >= distance)
                continue;
            return primitive.get().redirectionLight(ray, displayable, *impact);
        }
        result.applyDistance(distance, this->_power);
        return result;
    }

    void PointLightEntity::setColor(const Images::Color &color) {
        this->_color = color;
    }

    bool PointLightEntity::isAmbient() const
    {
        return false;
    }
}
