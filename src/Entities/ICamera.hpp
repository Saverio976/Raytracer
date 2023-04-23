/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ICamera.hpp
*/

#ifndef ICAMERA_HPP_
    #define ICAMERA_HPP_
    #include "Transform/Vector2i.hpp"

namespace Scenes {
    /**
     * @brief The ICamera class
     *
     * class that represent a camera
     * (perspective, orthographic, panoramic, ...)
     */
    class ICamera {
        public:
            virtual ~ICamera() = default;
            /**
             * @brief Get the focal (distance from the camera)
             *
             * @return the focal
             */
            virtual float getFocal() const = 0;
            /**
             * @brief Set the focal (distance from the camera)
             *
             * @param value the focal
             */
            virtual void setFocal(float value) = 0;
            /**
             * @brief Set the size (of the screen)
             *
             * @param vector the size
             */
            virtual void setSize(const Vector2i &vector) = 0;
            /**
             * @brief Get the size (of the screen)
             *
             * @return the size
             */
            virtual const Vector2i &getSize() const = 0;

        protected:
        private:
    };
}

#endif /*ICAMERA_HPP_*/
