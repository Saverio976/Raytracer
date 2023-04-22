/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color.hpp
*/

#ifndef COLOR_HPP_
	#define COLOR_HPP_

namespace Scenes {
    class Color {
        public:
            Color(const Color &color);
            Color(float r, float g, float b, float a);
            ~Color();
            Color operator+(const Color &other);
            Color operator-(const Color &other);
            Color operator*(const Color &other);
            Color operator/(const Color &other);
            Color operator=(const Color &other);

        protected:
        private:
            float r;
            float g;
            float b;
            float a;
    };
}

#endif /*COLOR_HPP_*/