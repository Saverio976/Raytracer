/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntity.hpp
*/
#ifndef PLANEENTITY_HPP_
    #define PLANEENTITY_HPP_

    #include "ILogger.hpp"
    #include "IPrimitive.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Plane {
    class PlaneEntity : public RayTracer::Entities::IPrimitive {
        public:
            PlaneEntity(const Scenes::ISetting &config, ILogger &logger);
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
    };
}

#endif /*PLANEENTITY_HPP_*/
