/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color.cpp
*/

#include "Color.hpp"

namespace RayTracer::Images {
    Color::Color(float r, float g, float b, float a) : _r(r), _g(g), _b(b), _a(a) { }

    Color Color::operator+(const Color &other) const {
        float new_r = this->_r + other[Types::RED];
        float new_g = this->_g + other[Types::GREEN];
        float new_b = this->_b + other[Types::BLUE];
        float new_a = this->_a + other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator-(const Color &other) const {
        float new_r = this->_r - other[Types::RED];
        float new_g = this->_g - other[Types::GREEN];
        float new_b = this->_b - other[Types::BLUE];
        float new_a = this->_a - other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator*(const Color &other) const {
        float new_r = this->_r * other[Types::RED];
        float new_g = this->_g * other[Types::GREEN];
        float new_b = this->_b * other[Types::BLUE];
        float new_a = this->_a * other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator/(const Color &other) const {
        float new_r = this->_r / other[Types::RED];
        float new_g = this->_g / other[Types::GREEN];
        float new_b = this->_b / other[Types::BLUE];
        float new_a = this->_a / other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color &Color::operator=(const Color &other) {
        this->_mutex.lock();
        this->_r = other[Types::RED];
        this->_g = other[Types::GREEN];
        this->_b = other[Types::BLUE];
        this->_a = other[Types::ALPHA];
        this->_mutex.unlock();
        return *this;
    }

    const float &Color::operator[](const Color::Types &type) const {
        switch (type) {
            case Types::RED:
                return this->_r;
            case Types::GREEN:
                return this->_g;
            case Types::BLUE:
                return this->_b;
            case Types::ALPHA:
                return this->_a;
            default:
                throw std::runtime_error("Error color: undefined type");
        }
    }

    float &Color::operator[](const Color::Types &type) {
        switch (type) {
            case Types::RED:
                return this->_r;
            case Types::GREEN:
                return this->_g;
            case Types::BLUE:
                return this->_b;
            case Types::ALPHA:
                return this->_a;
            default:
                throw std::runtime_error("Error color: undefined type");
        }
    }

    void Color::set(const Types &type, float value) {
        this->_mutex.lock();
        switch (type) {
            case Types::RED:
                this->_r = value;
                break;
            case Types::GREEN:
                this->_g = value;
                break;
            case Types::BLUE:
                this->_b = value;
                break;
            case Types::ALPHA:
                this->_a = value;
                break;
            default:
                throw std::runtime_error("Error color: undefined type");
        }
        this->_mutex.unlock();
    }
}

ostream& operator<<(ostream& os, const RayTracer::Images::Color& color) {
    float a = color[RayTracer::Images::Color::Types::ALPHA];
    float r = a * color[RayTracer::Images::Color::Types::RED] / 255;
    float g = a * color[RayTracer::Images::Color::Types::GREEN] / 255;
    float b = a * color[RayTracer::Images::Color::Types::BLUE] / 255;

    os << r << ' ' << g << ' ' << b;
    return os;
}
