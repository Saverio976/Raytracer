/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntity.hpp
*/
#ifndef PLANEENTITY_HPP_
    #define PLANEENTITY_HPP_

    #include "IPrimitive.hpp"
    #include "Transform.hpp"

namespace RayTracer::PluginsExt::Plane {
    class PlaneEntity : public RayTracer::Entities::IPrimitive {
        public:
            PlaneEntity(const Scenes::ISetting &config);
            Type getType() const final;
            Entities::Transform::ITransform &getTransform() final;
            const Entities::Transform::ITransform &getTransform() const final;
            bool isCollided(const Entities::Transform::Vector3f &point) const final;
            std::optional<Entities::Transform::Vector3f> isCollided(const Images::Ray &ray) const final;
            Images::Color getColor(const Images::Ray &ray, const Scenes::Displayable &displayable) const final;
        private:
            Entities::Transform::Transform _transform;
            RayTracer::Entities::Transform::Vector3f _size;
    };
}

#endif /*PLANEENTITY_HPP_*/