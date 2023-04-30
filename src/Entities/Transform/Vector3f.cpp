/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3f.cpp
*/

#include "Vector3f.hpp"
#include <cmath>

using namespace RayTracer::Entities::Transform;

Vector3f::Vector3f(const Vector3f &vector3f): _x(vector3f._x), _y(vector3f._y), _z(vector3f._z) {}

Vector3f::Vector3f(float x, float y, float z): _x(x), _y(y), _z(z) {}

Vector3f Vector3f::operator+(const Vector3f &other) const
{
    return {_x + other._x, _y + other._y, _z + other._z};
}

Vector3f Vector3f::operator-(const Vector3f &other) const
{
    return {_x - other._x, _y - other._y, _z - other._z};
}

Vector3f Vector3f::operator*(const Vector3f &other) const
{
    return Vector3f(_x * other._x, _y * other._y, _z * other._z);
}

Vector3f Vector3f::operator/(const Vector3f &other) const
{
    return {_x / other._x, _y / other._y, _z / other._z};
}

Vector3f &Vector3f::operator=(const Vector3f &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

float Vector3f::getX() const
{
    return _x;
}

float Vector3f::getY() const
{
    return _y;
}

float Vector3f::getZ() const
{
    return _z;
}

float Vector3f::getNorm() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

Vector3f Vector3f::getNormalized() const
{
    float norm = getNorm();
    return Vector3f(_x / norm, _y / norm, _z / norm);
}

float Vector3f::getDistance(const Vector3f &other) const
{
    float dx = _x - other._x;
    float dy = _y - other._y;
    float dz = _z - other._z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
