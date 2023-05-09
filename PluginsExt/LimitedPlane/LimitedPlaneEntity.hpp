/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** LimitedPlaneEntity.hpp
*/
#ifndef LIMITEDPLANEENTITY_HPP_
    #define LIMITEDPLANEENTITY_HPP_

    #include <functional>
    #include "ILogger.hpp"
    #include "IPrimitive.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::LimitedPlane {
    class LimitedPlaneEntity : public RayTracer::Entities::IPrimitive {
    public:
        LimitedPlaneEntity(const Scenes::ISetting &config, ILogger &logger);
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
        RayTracer::Entities::Transform::Vector3f _size;
        std::optional<std::reference_wrapper<Entities::IMaterial>> _material;
        ILogger &_logger;
    };
}

#endif /*LIMITEDPLANEENTITY_HPP_*/
