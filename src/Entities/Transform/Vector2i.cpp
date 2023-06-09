/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector2i.hpp
*/

#include <iostream>
#include "Vector2i.hpp"

namespace RayTracer::Entities::Transform {
    Vector2i::Vector2i(): _x(0), _y(0) {}
    Vector2i::Vector2i(const Vector2i &vector) : _x(vector._x), _y(vector._y) {}
    Vector2i::Vector2i(int width, int height) : _x(width), _y(height) {}

    Vector2i::Vector2i(const Scenes::ISetting &setting) {
        std::unique_ptr<Scenes::ISetting> tmp = setting.get("x");

        _x = static_cast<int>(*tmp);
        tmp = setting.get("y");
        _y = static_cast<int>(*tmp);
    }

    Vector2i Vector2i::operator+(const Vector2i &other) const
    {
        return {_x + other._x, _y + other._y};
    }

    Vector2i Vector2i::operator-(const Vector2i &other) const
    {
        return {_x - other._x, _y - other._y};
    }

    Vector2i Vector2i::operator*(const Vector2i &other) const
    {
        return {_x * other._x, _y * other._y};
    }

    Vector2i Vector2i::operator/(const Vector2i &other) const
    {
        if (other._x == 0 || other._y == 0) {
            std::cerr << "Error: division by zero" << std::endl;
            return {0, 0};
        }
        return {_x / other._x, _y / other._y};
    }

    Vector2i &Vector2i::operator=(const Vector2i &other) {
        _x = other._x;
        _y = other._y;
        return *this;
    }

    int Vector2i::getX() const {
        return _x;
    }

    int Vector2i::getY() const {
        return _y;
    }
}

std::ostream& operator<<(std::ostream& os, const RayTracer::Entities::Transform::Vector2i& vector) {
    os << "x = " << vector.getX() << " y = " << vector.getY() << std::endl;
    return os;
}
