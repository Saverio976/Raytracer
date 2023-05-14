/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image.cpp
*/

#include <cstddef>
#include <fstream>
#include <string>
#include "Image.hpp"

namespace RayTracer::Images {
    Image::Image(const Entities::Transform::Vector2i &size): _size(size)
    {
        std::size_t r = size.getY() * size.getX();

        _pixels.resize(r, Color(0, 0, 0, 0));
    }

    void Image::convertToPPM(const std::string &filePath) const {
        std::ofstream file;
        std::string buffer;

        file.open(filePath);
        if (!file.is_open())
            throw std::runtime_error("Error conversion PPM : Failed to open file");
        buffer += "P3\n";
        buffer += std::to_string(this->_size.getX()) + ' ' + std::to_string(this->_size.getY()) + '\n';
        buffer += "255\n";
        for (const Color &color : this->_pixels) {
            buffer += color.toString() + '\n';
        }
        file.write(buffer.c_str(), buffer.size());
        file.close();
    }

    const std::vector<Color> &Image::getPixelsList() const {
        return this->_pixels;
    }

    Image::PixelLine Image::operator[](std::size_t y) {
        return PixelLine(this->_size, y, this->_pixels);
    }

    const Image::PixelLine Image::operator[](std::size_t y) const {
        return Image::PixelLine(this->_size, y, this->_pixels);
    }

    Image::PixelLine::PixelLine(const Entities::Transform::Vector2i &size, const std::size_t &y, std::vector<Color> &pixels) :
        _size(size),
        _pixels(pixels),
        _pixelsConst(_pixels),
        _y(y) { }

    Image::PixelLine::PixelLine(const Entities::Transform::Vector2i &size, const std::size_t &y, const std::vector<Color> &pixels) :
        _size(size),
        _pixelsConst(_pixels),
        _pixels(_colors),
        _y(y) { }

    Color &Image::PixelLine::operator[](std::size_t x) {
        std::size_t toReach = this->_size.getX() * this->_y + x;
        return this->_pixels.at(toReach);
    }

    const Color &Image::PixelLine::operator[](std::size_t x) const {
        return this->_pixelsConst.at(this->_size.getX() * this->_y + x);
    }

    const Entities::Transform::Vector2i &Image::getSize() const {
        return this->_size;
    }
}
