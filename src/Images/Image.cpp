/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image.cpp
*/

#include "Image.hpp"
#include <iostream>
#include <fstream>

namespace RayTracer::Images {
    Image::Image(const Entities::Transform::Vector2i &size): _size(size) {
        size_t air = size->getX() * size->getY();

        for (size_t i = 0; i < air; i++)
            this->_pixels.push_back(Color(0, 0, 0, 0));
    }

    void Image::convertToPPM(const std::string &filePath) {
        std::ofstream file;

        file.open(filePath);
        if (!file.is_open())
            throw std::runtime_error("Error conversion PPM : Failed to open file");
        file << "P3" << std::endl;
        file << this->_size.getX() << ' ' << this->_size.getY() << std::endl;
        file << "255" << std::endl;
        for (const Color &color : this->_pixels)
            file << color << std::endl;
        file.close();
    }

    PixelLine Image::operator[](std::size_t y) {
        return PixelLine(this->_size, y, this->_pixels);
    }

    const PixelLine Image::operator[](std::size_t y) const {
        return PixelLine(this->_size, y, this->_pixels);
    }

    Image::PixelLine::PixelLine(const Entities::Transform::Vector2i &size, const std::size_t &y, std::vector<Color> &pixels) :
        _size(size),
        _pixels(pixels),
        _y(y) { }

    Color &Image::PixelLine::operator[](std::size_t x) {
        return this->_pixels.at(this->_size.getX() * this->_y + x);
    }

    const Color &Image::PixelLine::operator[](std::size_t x) const {
        return this->_pixels.at(this->_size.getX() * this->_y + x);
    }
}
