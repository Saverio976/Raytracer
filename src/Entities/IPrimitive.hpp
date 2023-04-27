/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_
    #include "IEntity.hpp"
    #include "IMaterial.hpp"
#include "Ray.hpp"
    #include "Transform/Vector3f.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The IPrimitive class
     *
     * class that represent a primitive (box, sphere, ...)
     */
    class IPrimitive : public IEntity {
        public:
            virtual ~IPrimitive() = default;
            /**
             * @brief Get the material
             *
             * @return the material
             */
            virtual IMaterial &getMaterial() = 0;
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
            virtual bool isCollided(const Images::Ray &ray) const = 0;

        protected:
        private:
    };
}

#endif /*IPRIMITIVE_HPP_*/
