/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_
    #include <optional>
    #include "Color.hpp"
    #include "IDisplayable.hpp"
    #include "IEntity.hpp"
    #include "IMaterial.hpp"
    #include "Ray.hpp"
    #include "Vector3f.hpp"
    #include "IEntity.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The IPrimitive class
     *
     * class that represent a primitive (box, sphere, ...)
     */
    class IPrimitive: public IEntity {
        public:
            virtual ~IPrimitive() = default;
            /**
             * @brief Get the material
             *
             * @return the material
             */
            virtual Images::Color getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
                const Transform::Vector3f &intersect) const = 0;
            /**
             * @brief Check if the point is collided with the box
             *
             * @param point the point
             *
             * @return true if the point is collided
             */
            virtual bool isCollided(const Transform::Vector3f &point) const = 0;
            /**
             * @brief Check if the ray is collided
             *
             * @param ray the ray
             *
             * @return true if the ray is collided
             */
            virtual std::optional<Transform::Vector3f> isCollided(const Images::Ray &ray) const = 0;
            /**
             * @brief this function is called when the object intercept the ray light
             *
             * @param ray the ray between the light and the object
             * @param displayable the displayable
             * @param intersect the intersection point between this point and the ray
             *
             * @return the color of the shadow
             */
            virtual Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
                const Transform::Vector3f &intersect) const = 0;

        protected:
        private:
    };
}

#endif /*IPRIMITIVE_HPP_*/
