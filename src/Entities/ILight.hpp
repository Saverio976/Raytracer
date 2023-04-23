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
            ~ILight() = default;
            /**
             * @brief Get the color
             *
             * @return the color
             */
            const Color &getColor() const;
            /**
             * @brief Get the color
             *
             * @param point the point of the impact
             *
             * @return the color
             */
            Color getColor(const Vector3f &point) const;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            void setColor(const Color &color);

        protected:
        private:
    };
}

#endif /*ILIGHT_HPP_*/
