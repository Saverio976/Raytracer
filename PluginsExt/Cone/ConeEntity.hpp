/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeEntity.hpp
*/

#ifndef RAYTRACER_CONEENTITY_HPP
    #define RAYTRACER_CONEENTITY_HPP

    #include <cmath>
    #include "ILogger.hpp"
    #include "IPrimitive.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Cone {
    class ConeEntity : public Entities::IPrimitive {
        public:
            ConeEntity(const Scenes::ISetting &config, ILogger &logger);
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
            std::optional<std::reference_wrapper<RayTracer::Entities::IMaterial>> _material;
    };
}

#endif //RAYTRACER_CONEENTITY_HPP
