/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TorusEntity.hpp
*/

#ifndef TORUSENTITY_HPP_
	#define TORUSENTITY_HPP_

#include "ILogger.hpp"
#include "IPrimitive.hpp"
#include "Transform.hpp"
#include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Torus {
    class TorusEntity : public RayTracer::Entities::IPrimitive {
    public:
        TorusEntity(const Scenes::ISetting &config, ILogger &logger);
        Type getType() const final;
        Entities::Transform::ITransform &getTransform() final;
        const Entities::Transform::ITransform &getTransform() const final;
        bool isCollided(const Entities::Transform::Vector3f &point) const final;
        std::optional<Entities::Transform::Vector3f> isCollided(const Images::Ray &ray) const final;
        Images::Color getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
            const Entities::Transform::Vector3f &intersect) const final;
        Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
            const Entities::Transform::Vector3f &intersect) const final;
    private:
        Entities::Transform::Transform _transform;
        std::optional<std::reference_wrapper<RayTracer::Entities::IMaterial>> _material;
        ILogger &_logger;
        double _minRadius;
        double _maxRadius;
    };
}

#endif /*TORUSENTITY_HPP_*/