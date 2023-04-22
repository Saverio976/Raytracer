/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ICamera.hpp
*/

#ifndef ICAMERA_HPP_
	#define ICAMERA_HPP_
    #include "Vector2i.hpp"

namespace Scenes {
    class ICamera {
        public:
            ~ICamera() = default;
            float getFocal() const;
            void setFocal(float value);
            void setSize(const Vector2i &vector);
            const Vector2i &getSize() const;

        protected:
        private:
    };
}

#endif /*ICAMERA_HPP_*/
