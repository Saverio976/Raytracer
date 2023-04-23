/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight.hpp
*/

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_
    #include "../Images/Color.hpp"
    #include "Transform/Vector3f.hpp"

namespace Scenes {
    /**
     * @brief The ILight class
     *
     * class that represent a light
     */
    class ILight {
        public:
            virtual ~ILight() = default;
            /**
             * @brief Get the color
             *
             * @return the color
             */
            virtual const Color &getColor() const = 0;
            /**
             * @brief Get the color
             *
             * @param point the point of the impact
             *
             * @return the color
             */
            virtual Color getColor(const Vector3f &point) const = 0;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            virtual void setColor(const Color &color) = 0;

        protected:
        private:
    };
}

#endif /*ILIGHT_HPP_*/
