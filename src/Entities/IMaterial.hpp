/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_

    #include "Ray.hpp"
    #include "Color.hpp"
    #include "IDisplayable.hpp"
    #include "ITransform.hpp"
    #include "Vector3f.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The IMaterial class
     *
     * class that represent a material (color/texture)
     */
    class IMaterial {
        public:
            virtual ~IMaterial() = default;
            /**
             * @brief Get the color
             *
             * @param centerObj the center of the object impacted
             * @param intersect the intersection point on the object
             * @param displayable the displayable objects
             *
             * @return the color
             */
            virtual Images::Color getColor(const Images::Ray &ray, const Transform::ITransform &centerObj, const Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const = 0;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            virtual void setColor(const Images::Color &color) = 0;

        protected:
        private:
    };
}

#endif /*IMATERIAL_HPP_*/
