/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color.cpp
*/

#include "Color.hpp"
#include "ISetting.hpp"
#include <memory>

namespace RayTracer::Images {

    Color::Color(const Color &color) {
        this->_r = color[Color::Types::RED];
        this->_g = color[Color::Types::GREEN];
        this->_b = color[Color::Types::BLUE];
        this->_a = color[Color::Types::ALPHA];
    }

    Color::Color(double r, double g, double b, double a) : _r(r), _g(g), _b(b), _a(a) { }

    Color::Color(const Scenes::ISetting &setting) {
        std::unique_ptr<Scenes::ISetting> tmp = setting.get("r");

        this->_r = static_cast<double>(*tmp);
        tmp = setting.get("g");
        this->_g = static_cast<double>(*tmp);
        tmp = setting.get("b");
        this->_b = static_cast<double>(*tmp);
        tmp = setting.get("a");
        this->_a = static_cast<double>(*tmp);
    }

    Color Color::operator+(const Color &other) const {
        double new_r = this->_r + other[Types::RED];
        double new_g = this->_g + other[Types::GREEN];
        double new_b = this->_b + other[Types::BLUE];
        double new_a = this->_a + other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator-(const Color &other) const {
        double new_r = this->_r - other[Types::RED];
        double new_g = this->_g - other[Types::GREEN];
        double new_b = this->_b - other[Types::BLUE];
        double new_a = this->_a - other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator*(const Color &other) const {
        double new_r = this->_r * other[Types::RED];
        double new_g = this->_g * other[Types::GREEN];
        double new_b = this->_b * other[Types::BLUE];
        double new_a = this->_a * other[Types::ALPHA];
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator/(const Color &other) const {
        double new_r = this->_r / other[Types::RED];
        double new_g = this->_g / other[Types::GREEN];
        double new_b = this->_b / other[Types::BLUE];
        double new_a = this->_a / other[Types::ALPHA];
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

    const double &Color::operator[](const Color::Types &type) const {
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

    double &Color::operator[](const Color::Types &type) {
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

    void Color::set(const Types &type, double value) {
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

std::ostream& operator<<(std::ostream& os, const RayTracer::Images::Color& color) {
    double a = color[RayTracer::Images::Color::Types::ALPHA];
    double r = a * color[RayTracer::Images::Color::Types::RED] / 255;
    double g = a * color[RayTracer::Images::Color::Types::GREEN] / 255;
    double b = a * color[RayTracer::Images::Color::Types::BLUE] / 255;

    os << r << ' ' << g << ' ' << b;
    return os;
}
