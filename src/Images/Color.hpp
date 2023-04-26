/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color.hpp
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_
    #include <mutex>

namespace RayTracer::Images {
    /**
     * @brief The Color class
     *
     * class that represent a color
     */
    class Color {
        public:
            /**
             * @brief Type of color
             */
            enum class Types {
                RED,
                GREEN,
                BLUE,
                ALPHA
            };
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
            Color operator+(const Color &other) const;
            /**
             * @brief Subtraction two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator-(const Color &other) const;
            /**
             * @brief Multiplication two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator*(const Color &other) const;
            /**
             * @brief Division two colors
             *
             * @param other the other color
             *
             * @return the new color
             */
            Color operator/(const Color &other) const;
            /**
             * @brief Assign a color
             *
             * @param other the other color
             *
             * @return the same color modified
             */
            Color &operator=(const Color &other);
            /**
             * @brief Get the color
             *
             * @param type the color type
             *
             * @return the color
             */
            const float &operator[](const Types &type) const;
            /**
             * @brief Get the color (not thread safe !!)
             *
             * @param type the color type
             *
             * @return the color
             */
            float &operator[](const Types &type);
            /**
             * @brief set the color (thread safe)
             *
             * @param type the color type
             *
             * @return the color
             */
            void set(const Types &type, float value);

        protected:
        private:
            float _r;
            float _g;
            float _b;
            float _a;
            std::mutex _mutex;
    };
}

#endif /*COLOR_HPP_*/
