/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color.hpp
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_
    #include <mutex>
    #include <ostream>
    #include "ISetting.hpp"

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
            Color(double r, double g, double b, double a);
            /**
             * @brief Construct a new Color object with setting
             *
             * Key needed: r, g, b, a
             *
             * @param setting the setting
             */
            Color(const Scenes::ISetting &setting);
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
            const double &operator[](const Types &type) const;
            /**
             * @brief Get the color (not thread safe !!)
             *
             * @param type the color type
             *
             * @return the color
             */
            double &operator[](const Types &type);
            /**
             * @brief set the color (thread safe)
             *
             * @param type the color type
             *
             * @return the color
             */
            void set(const Types &type, double value);
            /**
             * @brief apply alpha of the color with background (thread safe)
             *
             * @param other the background
             */
            void applyAlpha(const Color &background);
            /**
             * @brief merge color with another one (thread safe)
             *
             * @param other the color that will be merged
             */
            void mergeColor(const Color &other);
            /**
             * @brief apply distance in the color
             *
             * @param distance the distance
             * @param distance max distance (exemple: watt of the light)
             */
            void applyDistance(double distance, double maxDistance);

        private:
            double _r;
            double _g;
            double _b;
            double _a;
            std::mutex _mutex;
    };
}

std::ostream& operator<<(std::ostream& os, const RayTracer::Images::Color& color);

#endif /*COLOR_HPP_*/
