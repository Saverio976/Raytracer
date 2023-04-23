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
            ~ICamera() = default;
            /**
             * @brief Get the focal (distance from the camera)
             *
             * @return the focal
             */
            float getFocal() const;
            /**
             * @brief Set the focal (distance from the camera)
             *
             * @param value the focal
             */
            void setFocal(float value);
            /**
             * @brief Set the size (of the screen)
             *
             * @param vector the size
             */
            void setSize(const Vector2i &vector);
            /**
             * @brief Get the size (of the screen)
             *
             * @return the size
             */
            const Vector2i &getSize() const;

        protected:
        private:
    };
}

#endif /*ICAMERA_HPP_*/
