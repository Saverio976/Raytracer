/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Box.hpp
*/
#ifndef BOX_HPP_
	#define BOX_HPP_
    #include "Vector3f.hpp"

namespace Scenes {
    class Box {
        public:
            Box(const Vector3f &position, float width, float length, float height);
            ~Box();
            bool isInside(const Vector3f &point) const;

        protected:
        private:
            Vector3f position;
            float width;
            float length;
            float height;
    };
}

#endif /*BOX_HPP_*/
