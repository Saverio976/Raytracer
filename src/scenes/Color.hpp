/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color.hpp
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_

namespace Scenes {
    /**
     * @brief The Color class
     *
     * class that represent a color
     */
    class Color {
        public:
            ~Color() = default;
            /**
             * @brief Construct a new Color object
             *
             * @param color the color
             */
            Color(const Color &color);
            /**
             * @brief Construct a new Color object
             *
             * @param r red
             * @param g green
             * @param b blue
             * @param a alpha
             */
            Color(float r, float g, float b, float a);
            /**
             * @brief Addition two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator+(const Color &other);
            /**
             * @brief Subtraction two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator-(const Color &other);
            /**
             * @brief Multiplication two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator*(const Color &other);
            /**
             * @brief Division two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator/(const Color &other);
            /**
             * @brief Assign a color
             *
             * @param other the other color
             *
             * @return the same color modified
             */
            Color &operator=(const Color &other);

        protected:
        private:
            float r;
            float g;
            float b;
            float a;
    };
}

#endif /*COLOR_HPP_*/
