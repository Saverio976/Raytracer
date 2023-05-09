/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderEntity.hpp
*/

#ifndef CYLINDERENTITY_HPP
    #define CYLINDERENTITY_HPP

    #include <optional>
    #include "IPrimitive.hpp"
    #include "ISetting.hpp"
    #include "ILogger.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"
    #include "Ray.hpp"

namespace RayTracer::PluginsExt::LimitedCylinder {
    class LimitedCylinderEntity : public Entities::IPrimitive {
        public:
            LimitedCylinderEntity(const Scenes::ISetting &config, ILogger &logger);

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
            std::array<double, 2> isCollidedInfiniteCylinder(const Images::Ray &ray) const;
            Entities::Transform::Transform _transform;
            Entities::Transform::Vector3f _direction;
            double _radius;
            ILogger &_logger;
            std::optional<std::reference_wrapper<RayTracer::Entities::IMaterial>> _material;
            double _height;
    };
}

#endif
