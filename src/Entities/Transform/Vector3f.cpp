/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3f.cpp
*/

#include <cmath>
#include <memory>
#include "ISetting.hpp"
#include "Vector3f.hpp"

namespace RayTracer::Entities::Transform {
    Vector3f::Vector3f(const Vector3f &vector3f): _x(vector3f._x), _y(vector3f._y), _z(vector3f._z) {}

    Vector3f::Vector3f(double x, double y, double z): _x(x), _y(y), _z(z) {}

    Vector3f::Vector3f(): _x(0), _y(0), _z(0) {}

    Vector3f::Vector3f(const Scenes::ISetting &setting)
    {
        std::unique_ptr<Scenes::ISetting> tmp = setting.get("x");

        _x = static_cast<double>(*tmp);
        tmp = setting.get("y");
        _y = static_cast<double>(*tmp);
        tmp = setting.get("z");
        _z = static_cast<double>(*tmp);
    }

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
        return {_x * other._x, _y * other._y, _z * other._z};
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

    double Vector3f::getX() const
    {
        return _x;
    }

    double Vector3f::getY() const
    {
        return _y;
    }

    double Vector3f::getZ() const
    {
        return _z;
    }

    double Vector3f::getNorm() const
    {
        return std::sqrt(_x * _x + _y * _y + _z * _z);
    }

    Vector3f Vector3f::getNormalized() const
    {
        double norm = getNorm();
        return {_x / norm, _y / norm, _z / norm};
    }

    double Vector3f::getDistance(const Vector3f &other) const
    {
        double dx = _x - other._x;
        double dy = _y - other._y;
        double dz = _z - other._z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    double Vector3f::dot(const RayTracer::Entities::Transform::Vector3f &other) const {
        return _x * other.getX() + _y * other.getY() + _z * other.getZ();
    }

    Vector3f Vector3f::toDegrees() const {
        return {
            this->_x * (180 / M_PI),
            this->_y * (180 / M_PI),
            this->_z * (180 / M_PI)
        };
    }

    Vector3f Vector3f::toRadians() const {
        return {
            this->_x * (M_PI / 180),
            this->_y * (M_PI / 180),
            this->_z * (M_PI / 180)
        };
    }

    Vector3f Vector3f::rotateVector(const Vector3f &direction, const Vector3f &rotation) const {
        Vector3f angle = rotation.toRadians();
        float xRotation;
        float yRotation;
        float zRotation;

        xRotation = direction.getX();
        yRotation = direction.getY() * std::cos(angle.getX()) - direction.getZ() * std::sin(angle.getX());
        zRotation = direction.getY() * std::sin(angle.getX()) + direction.getZ() * std::cos(angle.getX());

        xRotation = xRotation * std::cos(angle.getY()) + zRotation * std::sin(angle.getY());
        yRotation = yRotation;
        zRotation = -xRotation * std::sin(angle.getY()) + zRotation * std::cos(angle.getY());

        xRotation = xRotation * std::cos(angle.getZ()) - yRotation * std::sin(angle.getZ());
        yRotation = xRotation * std::sin(angle.getZ()) + yRotation * std::cos(angle.getZ());
        zRotation = zRotation;

        return {xRotation, yRotation, zRotation};
    }

/*
 *
  PVector rotateX(float angle) {
    float cosa = cos(angle);
    float sina = sin(angle);
    float tempy = y;
    y = cosa * y - sina * z;
    z = cosa * z + sina * tempy;
    return this;
  }

  PVector rotateY(float angle) {
    float cosa = cos(angle);
    float sina = sin(angle);
    float tempz = z;
    z = cosa * z - sina * x;
    x = cosa * x + sina * tempz;
    return this;
  }

  PVector rotateZ(float angle) {
    float cosa = cos(angle);
    float sina = sin(angle);
    float tempx = x;
    x = cosa * x - sina * y;
    y = cosa * y + sina * tempx;
    return this;
  }
 */

    Vector3f Vector3f::rotateX(float angle) const
    {
        Vector3f newVector = *this;
        Vector3f rad = Vector3f(angle, angle, angle).toRadians();

        float cosa = std::cos(rad.getX());
        float sina = std::sin(rad.getX());
        newVector._y = cosa * _y - sina * _z;
        newVector._z = cosa * _z + sina * _y;
        return newVector;
    }

    Vector3f Vector3f::rotateY(float angle) const
    {
        Vector3f newVector = *this;
        Vector3f rad = Vector3f(angle, angle, angle).toRadians();

        float cosa = std::cos(rad.getX());
        float sina = std::sin(rad.getX());
        newVector._z = cosa * _z - sina * _x;
        newVector._x = cosa * _x + sina * _z;
        return newVector;
    }

    Vector3f Vector3f::rotateZ(float angle) const
    {
        Vector3f newVector = *this;
        Vector3f rad = Vector3f(angle, angle, angle).toRadians();

        float cosa = cos(rad.getX());
        float sina = sin(rad.getX());
        newVector._x = cosa * _x - sina * _y;
        newVector._y = cosa * _y + sina * _x;
        return newVector;
    }

    double Vector3f::getAngle(const Vector3f &a, const Vector3f &c) const {
        double dot_product = (this->getX() - a.getX()) * (c.getX() - this->getX()) + (this->getY() - a.getY()) * (c.getY() - this->getY()) + (this->getZ() - a.getZ()) * (c.getZ() - this->getZ());
        double mag_ab = std::sqrt((this->getX() - a.getX()) * (this->getX() - a.getX()) + (this->getY() - a.getY()) * (this->getY() - a.getY()) + (this->getZ() - a.getZ()) * (this->getZ() - a.getZ()));
        double mag_bc = std::sqrt((c.getX() - this->getX()) * (c.getX() - this->getX()) + (c.getY() - this->getY()) * (c.getY() - this->getY()) + (c.getZ() - this->getZ()) * (c.getZ() - this->getZ()));
        double cos_angle = dot_product / (mag_ab * mag_bc);
        return std::acos(cos_angle) * (180 / M_PI);
    }
}

std::ostream& operator<<(std::ostream& os, const RayTracer::Entities::Transform::Vector3f& vector) {
    os << "x = " << vector.getX() << " y = " << vector.getY() << " z = " << vector.getZ() << std::endl;
    return os;
}
