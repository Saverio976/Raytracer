/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray.hpp
*/

#ifndef RAY_HPP
    #define RAY_HPP

#include "Vector3f.hpp"
namespace RayTracer::Images {
    /**
     * @brief The Ray class
     *
     * class that represent a ray
     */
    class Ray {
        public:
            /**
             * @brief Ray constructor
             *
             * calcul the normal between `startCamera` and `screenPos`
             * and set the origin to `screenPos`
             *
             * @param startCamera the camera position
             * @param screenPos the screen position
             */
            Ray(const Entities::Transform::Vector3f &startCamera, const Entities::Transform::Vector3f &screenPos);
            /**
             * @brief Get origin (`screenPos`)
             *
             * @return the origin
             */
            const Entities::Transform::Vector3f &getOrigin() const;
            /**
             * @brief Get direction (the normal)
             *
             * @return the direction
             */
            const Entities::Transform::Vector3f &getDirection() const;
            /**
             * @brief Get step (the current position of the ray)
             *
             * @return the step
             */
            const Entities::Transform::Vector3f &getStep() const;
            /**
             * @brief Add `t*normal`
             *
             * @param t the step to add
             */
            void operator+=(float t);
            /**
             * @brief Substract `t*normal`
             *
             * @param t the step to substract
             */
            void operator-=(float t);
            /**
             * @brief Increment `1*normal`
             *
             * @return the incremented
             */
            Ray &operator++();
            /**
             * @brief Decrement `1*normal`
             *
             * @return the decremented
             */
            Ray &operator--();

        private:
            Entities::Transform::Vector3f _origin;
            Entities::Transform::Vector3f _normal;
            Entities::Transform::Vector3f _step;
    };
}

#endif
