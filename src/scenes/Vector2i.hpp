/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector2i.hpp
*/
#ifndef VECTOR2I_HPP_
	#define VECTOR2I_HPP_

namespace Scenes {
    class Vector2i {
        public:
            Vector2i(const Vector2i &vector);
            Vector2i(int width, int height);
            ~Vector2i();
            Vector2i operator+(const Vector2i &other);
            Vector2i operator-(const Vector2i &other);
            Vector2i operator*(const Vector2i &other);
            Vector2i operator/(const Vector2i &other);
            Vector2i operator=(const Vector2i &other);

        protected:
        private:
            int x;
            int y;
    };
}

#endif /*VECTOR2I_HPP_*/
