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

        this->_r = (this->_r < 0) ? 0 : (this->_r > 255) ? 255 : this->_r;
        this->_g = (this->_g < 0) ? 0 : (this->_g > 255) ? 255 : this->_g;
        this->_b = (this->_b < 0) ? 0 : (this->_b > 255) ? 255 : this->_b;
        this->_a = (this->_a < 0) ? 0 : (this->_a > 255) ? 255 : this->_a;
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
        this->_r = (this->_r < 0) ? 0 : (this->_r > 255) ? 255 : this->_r;
        this->_g = (this->_g < 0) ? 0 : (this->_g > 255) ? 255 : this->_g;
        this->_b = (this->_b < 0) ? 0 : (this->_b > 255) ? 255 : this->_b;
        this->_a = (this->_a < 0) ? 0 : (this->_a > 255) ? 255 : this->_a;
    }

    Color Color::operator+(const Color &other) const {
        double new_r = this->_r + other[Types::RED];
        double new_g = this->_g + other[Types::GREEN];
        double new_b = this->_b + other[Types::BLUE];
        double new_a = this->_a + other[Types::ALPHA];

        new_r = (new_r < 0) ? 0 : (new_r > 255) ? 255 : new_r;
        new_g = (new_g < 0) ? 0 : (new_g > 255) ? 255 : new_g;
        new_b = (new_b < 0) ? 0 : (new_b > 255) ? 255 : new_b;
        new_a = (new_a < 0) ? 0 : (new_a > 255) ? 255 : new_a;
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator-(const Color &other) const {
        double new_r = this->_r - other[Types::RED];
        double new_g = this->_g - other[Types::GREEN];
        double new_b = this->_b - other[Types::BLUE];
        double new_a = this->_a - other[Types::ALPHA];

        new_r = (new_r < 0) ? 0 : (new_r > 255) ? 255 : new_r;
        new_g = (new_g < 0) ? 0 : (new_g > 255) ? 255 : new_g;
        new_b = (new_b < 0) ? 0 : (new_b > 255) ? 255 : new_b;
        new_a = (new_a < 0) ? 0 : (new_a > 255) ? 255 : new_a;
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator*(const Color &other) const {
        double new_r = this->_r * other[Types::RED];
        double new_g = this->_g * other[Types::GREEN];
        double new_b = this->_b * other[Types::BLUE];
        double new_a = this->_a * other[Types::ALPHA];

        new_r = (new_r < 0) ? 0 : (new_r > 255) ? 255 : new_r;
        new_g = (new_g < 0) ? 0 : (new_g > 255) ? 255 : new_g;
        new_b = (new_b < 0) ? 0 : (new_b > 255) ? 255 : new_b;
        new_a = (new_a < 0) ? 0 : (new_a > 255) ? 255 : new_a;
        return {new_r, new_g, new_b, new_a};
    }

    Color Color::operator/(const Color &other) const {
        double other_r = other[Types::RED];
        double new_r = (other_r) ? this->_r / other_r : 0;
        double other_g = other[Types::GREEN];
        double new_g = (other_g) ? this->_g / other_g : 0;
        double other_b = other[Types::BLUE];
        double new_b = (other_b) ? this->_b / other_b : 0;
        double other_a = other[Types::ALPHA];
        double new_a = (other_a) ? this->_a / other_a : 0;

        new_r = (new_r < 0) ? 0 : (new_r > 255) ? 255 : new_r;
        new_g = (new_g < 0) ? 0 : (new_g > 255) ? 255 : new_g;
        new_b = (new_b < 0) ? 0 : (new_b > 255) ? 255 : new_b;
        new_a = (new_a < 0) ? 0 : (new_a > 255) ? 255 : new_a;
        return {new_r, new_g, new_b, new_a};
    }

    Color &Color::operator=(const Color &other) {
        this->_mutex.lock();
        this->_r = other[Types::RED];
        this->_g = other[Types::GREEN];
        this->_b = other[Types::BLUE];
        this->_a = other[Types::ALPHA];

        this->_r = (this->_r < 0) ? 0 : (this->_r > 255) ? 255 : this->_r;
        this->_g = (this->_g < 0) ? 0 : (this->_g > 255) ? 255 : this->_g;
        this->_b = (this->_b < 0) ? 0 : (this->_b > 255) ? 255 : this->_b;
        this->_a = (this->_a < 0) ? 0 : (this->_a > 255) ? 255 : this->_a;
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

    void Color::applyAlpha(const RayTracer::Images::Color &background) {
        double alphaFloat = this->_a / 255.0f;

        this->_mutex.lock();
        this->_r = this->_r * alphaFloat + background[Types::RED] * (1 - alphaFloat);
        this->_g = this->_g * alphaFloat + background[Types::GREEN] * (1 - alphaFloat);
        this->_b = this->_b * alphaFloat + background[Types::BLUE] * (1 - alphaFloat);
        this->_a = 255;
        this->_mutex.unlock();
    }

    void Color::mergeColor(const RayTracer::Images::Color &other) {
        this->_mutex.lock();
        this->_r = other[Types::RED] * this->_r / 255;
        this->_g = other[Types::GREEN] * this->_g / 255;
        this->_b = other[Types::BLUE] * this->_b / 255;
        this->_mutex.unlock();
    }
}

std::ostream& operator<<(std::ostream& os, const RayTracer::Images::Color& color) {
    double a = color[RayTracer::Images::Color::Types::ALPHA];
    int r = a * color[RayTracer::Images::Color::Types::RED] / 255;
    int g = a * color[RayTracer::Images::Color::Types::GREEN] / 255;
    int b = a * color[RayTracer::Images::Color::Types::BLUE] / 255;

    r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    os << r << ' ' << g << ' ' << b;
    return os;
}
