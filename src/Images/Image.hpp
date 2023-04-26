/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image.hpp
*/

#ifndef IMAGE_HPP_
    #define IMAGE_HPP_

#include <cstddef>
#include <string>
#include <list>
#include "Color.hpp"
#include "Vector2i.hpp"

namespace RayTracer::Images {
    /**
     * @brief The Image class
     *
     * class that represent an image
     */
    class Image {
        public:
            /**
             * @brief PixelLine class
             *
             * class that represent a PixelLine (the line of pixel at line `y`)
             */
            class PixelLine {
                public:
                    /**
                     * @brief PixelLine
                     *
                     * @param size the size
                     * @param y the y
                     * @param pixels the orginal pixels
                     */
                    PixelLine(const Entities::Transform::Vector2i &size, const std::size_t &y, std::vector<Color> &pixels);
                    /**
                     * @brief Get the color (const)
                     *
                     * @param x the x
                     *
                     * @return the color
                     */
                    const Color &operator[](std::size_t x) const;
                    /**
                     * @brief Get the color
                     *
                     * @param x the x
                     *
                     * @return the color
                     */
                    Color &operator[](std::size_t x);

                private:
                    const Entities::Transform::Vector2i &_size;
                    const std::size_t &_y;
                    std::vector<Color> &_pixels;
            };
            /**
             * @brief Image
             *
             * @param size the size
             */
            Image(const Entities::Transform::Vector2i &size);
            /**
             * @brief convertToPPM file
             *
             * @param filePath the file
             */
            void convertToPPM(const std::string &filePath);
            // sf::Texture convertToSfTexture();
            /**
             * @brief Get the pixels line at line `y` (const)
             *
             * @param y the y
             *
             * @return the pixels line
             */
            const PixelLine operator[](std::size_t y) const;
            /**
             * @brief Get the pixels line at line `y`
             *
             * @param y the y
             *
             * @return the pixels line
             */
            PixelLine operator[](std::size_t y);

        private:
            std::vector<Color> _pixels;
            Entities::Transform::Vector2i _size;
    };
}

#endif
