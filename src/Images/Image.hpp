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
    class Image {
        public:
            class PixelLine {
                public:
                    PixelLine(const Entities::Transform::Vector2i &size, const std::size_t &y, std::list<Color> &pixels);
                    const Color &operator[](std::size_t x) const;
                    Color &operator[](std::size_t x);

                private:
                    const Entities::Transform::Vector2i &_size;
                    const std::size_t &_y;
                    std::list<Color> &_pixels;
            };
            Image(const Entities::Transform::Vector2i &size);
            void convertToPPM(const std::string &filePath);
            // sf::Texture convertToSfTexture();
            const PixelLine operator[](std::size_t y) const;
            PixelLine operator[](std::size_t y);

        private:
            std::list<Color> _pixels;
    };
}

#endif
