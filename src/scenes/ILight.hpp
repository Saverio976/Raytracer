/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight.hpp
*/

#ifndef ILIGHT_HPP_
	#define ILIGHT_HPP_
    #include "Color.hpp"
    #include "Vector3f.hpp"

namespace Scenes {
    class ILight {
        public:
            ~ILight() = default;
            const Color &getColor() const;
            Color getColor(const Vector3f &point) const;
            void setColor(const Color &color);

        protected:
        private:
    };
}

#endif /*ILIGHT_HPP_*/
