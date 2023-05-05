/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeEntity.hpp
*/

#ifndef RAYTRACER_CONEENTITY_HPP
    #define RAYTRACER_CONEENTITY_HPP
    #include <cmath>
    #include "IPrimitive.hpp"
    #include "Transform.hpp"

namespace RayTracer::PluginsExt::Cone {
    class ConeEntity : public Entities::IPrimitive {
        public:
            ConeEntity(const Scenes::ISetting &config);
            Type getType() const final;
            Entities::Transform::ITransform &getTransform() final;
            const Entities::Transform::ITransform &getTransform() const final;
            bool isCollided(const Entities::Transform::Vector3f &point) const final;
            std::optional<Entities::Transform::Vector3f> isCollided(const Images::Ray &ray) const final;
            Images::Color getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const final;
        private:
            Entities::Transform::Transform _transform;
            double _angle;
    };
}

#endif //RAYTRACER_CONEENTITY_HPP
