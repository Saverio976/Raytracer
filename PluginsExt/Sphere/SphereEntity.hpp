/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereEntity.hpp
*/

#ifndef SPHEREENTITY_HPP_
    #define SPHEREENTITY_HPP_

    #include "IDisplayable.hpp"
    #include "ILogger.hpp"
    #include "IMaterial.hpp"
    #include "IPrimitive.hpp"
    #include "ISetting.hpp"
    #include "Transform.hpp"
    #include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Sphere {
    class SphereEntity : public RayTracer::Entities::IPrimitive {
        public:
            SphereEntity(const Scenes::ISetting &config, ILogger &logger);

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
            double _radius;
            std::optional<std::reference_wrapper<RayTracer::Entities::IMaterial>> _material;
            ILogger &_logger;
    };
}

#endif
