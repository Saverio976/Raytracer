/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_
    #include "IMaterial.hpp"
    #include "Transform/Vector3f.hpp"

namespace Scenes {
    /**
     * @brief The IPrimitive class
     *
     * class that represent a primitive (box, sphere, ...)
     */
    class IPrimitive {
        public:
            ~IPrimitive() = default;
            /**
             * @brief Get the material
             *
             * @return the material
             */
            IMaterial &getMaterial();
            /**
             * @brief Check if the point is collided with the box
             *
             * @param point the point
             *
             * @return true if the point is collided
             */
            bool isCollided(const Vector3f &point) const;

        protected:
        private:
    };
}

#endif /*IPRIMITIVE_HPP_*/
