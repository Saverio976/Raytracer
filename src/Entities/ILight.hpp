/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight.hpp
*/

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_
    #include "Color.hpp"
    #include "IDisplayable.hpp"
    #include "Transform/Vector3f.hpp"
    #include "IEntity.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The ILight class
     *
     * class that represent a light
     */
    class ILight: public IEntity {
        public:
            virtual ~ILight() = default;
            /**
             * @brief Get the color
             *
             * @return the color
             */
            virtual const Images::Color &getColor() const = 0;
            /**
             * @brief Get the color
             *
             * @param point the point of the impact
             *
             * @return the color
             */
            virtual Images::Color getColor(const Transform::Vector3f &point, const Scenes::IDisplayable &displayable) const = 0;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            virtual void setColor(const Images::Color &color) = 0;
            /**
             * @brief Check if the light is ambient
             *
             * @return true if the light is ambient
             */
            virtual bool isAmbient() const = 0;

        protected:
        private:
    };
}

#endif /*ILIGHT_HPP_*/
