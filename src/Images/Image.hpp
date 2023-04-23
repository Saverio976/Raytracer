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

class Image {
    public:
        class PixelLine {
            public:
                PixelLine(const Scenes::Vector2i &size, const std::size_t &y, std::list<Scenes::Color> &pixels);
                const Scenes::Color &operator[](std::size_t x) const;
                Scenes::Color &operator[](std::size_t x);

            private:
                Scenes::Vector2i _size;
                std::size_t _y;
                std::list<Scenes::Color> &_pixels;
        };
        Image(const Scenes::Vector2i &size);
        void convertToPPM(const std::string &filePath);
        // sf::Texture convertToSfTexture();
        const PixelLine operator[](std::size_t y) const;
        PixelLine operator[](std::size_t y);

    private:
        std::list<Scenes::Color> _pixels;
};

#endif
