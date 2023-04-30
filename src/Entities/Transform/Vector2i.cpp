/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector2i.hpp
*/

#include <iostream>
#include "Vector2i.hpp"

namespace RayTracer::Entities::Transform {
    Vector2i::Vector2i(const Vector2i &vector) : _x(vector._x), _y(vector._y) {}
    Vector2i::Vector2i(int width, int height) : _x(width), _y(height) {}

    Vector2i Vector2i::operator+(const Vector2i &other) {
        return Vector2i(_x + other._x, _y + other._y);
    }

    Vector2i Vector2i::operator-(const Vector2i &other) {
        return Vector2i(_x - other._x, _y - other._y);
    }

    Vector2i Vector2i::operator*(const Vector2i &other) {
        return Vector2i(_x * other._x, _y * other._y);
    }

    Vector2i Vector2i::operator/(const Vector2i &other) {
        if (other._x == 0 || other._y == 0) {
            std::cerr << "Error: division by zero" << std::endl;
            return Vector2i(0, 0);
        }
        return Vector2i(_x / other._x, _y / other._y);
    }

    Vector2i &Vector2i::operator=(const Vector2i &other) {
        _x = other._x;
        _y = other._y;
        return *this;
    }
}
