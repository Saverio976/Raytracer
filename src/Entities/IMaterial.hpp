/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_
    #include "../Images/Color.hpp"

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
             * @return the color
             */
            virtual const Images::Color &getColor() const = 0;
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
