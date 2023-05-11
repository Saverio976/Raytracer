/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TriangleEntity.hpp
*/

#ifndef RAYTRACER_TRIANGLEENTITY_HPP
    #define RAYTRACER_TRIANGLEENTITY_HPP
    #include <functional>
    #include "ILogger.hpp"
    #include "IPrimitive.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Triangle {
    class TriangleEntity : public RayTracer::Entities::IPrimitive {
    public:
        TriangleEntity(const Scenes::ISetting &config, ILogger &logger);
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
        std::optional<std::reference_wrapper<Entities::IMaterial>> _material;
        Entities::Transform::Vector3f _pointOne;
        Entities::Transform::Vector3f _pointTwo;
        Entities::Transform::Vector3f _pointThree;
        ILogger &_logger;
    };
}

#endif //RAYTRACER_TRIANGLEENTITY_HPP
