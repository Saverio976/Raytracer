//
// Created by sverm on 08/05/2023.
//

#ifndef RAYTRACER_LIMITEDCONEENTITY_HPP
#define RAYTRACER_LIMITEDCONEENTITY_HPP


#include <cmath>
#include "ILogger.hpp"
#include "IPrimitive.hpp"
#include "Transform.hpp"
#include "PlainMaterial.hpp"

namespace RayTracer::PluginsExt::LimitedCone {
    class LimitedConeEntity : public Entities::IPrimitive {
    public:
        LimitedConeEntity(const Scenes::ISetting &config, ILogger &logger);
        Type getType() const final;
        Entities::Transform::ITransform &getTransform() final;
        const Entities::Transform::ITransform &getTransform() const final;
        bool isCollided(const Entities::Transform::Vector3f &point) const final;
        std::optional<Entities::Transform::Vector3f> isCollided(const Images::Ray &ray) const final;
        Images::Color getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable, const Entities::Transform::Vector3f &intersect) const final;
        Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
            const Entities::Transform::Vector3f &intersect) const final;
    private:
        Entities::Transform::Transform _transform;
        double _angle;
        ILogger &_logger;
        Images::Color _color;
        double _height;
        PlainMaterial _material;
    };
}


#endif //RAYTRACER_LIMITEDCONEENTITY_HPP
