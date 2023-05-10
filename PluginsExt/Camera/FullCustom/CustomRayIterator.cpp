/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CustomRayIterator.cpp
*/

#include <cmath>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include "CustomRayIterator.hpp"
#include "ICamera.hpp"
#include "RayIterrator.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"

static const RayTracer::Entities::Transform::Vector3f baseDir(0, -1, 0);

namespace RayTracer::PluginsExt::Camera::FullCustom {
    // -----------------------------------------------------------------------
    // CustomRayIterator::iterrator
    // -----------------------------------------------------------------------

    CustomRayIterator::Iterator::Iterator(const Entities::Transform::Vector3f &cameraPos, const Entities::Transform::Vector2i &screenSize, const Entities::Transform::Vector3f &fovXYZ, const Entities::Transform::Vector3f &fov, std::size_t x, std::size_t y):
        _cameraPos(cameraPos),
        _screenSize(screenSize),
        _fovXYZ(fovXYZ),
        _fov(fov),
        _x(x),
        _y(y),
        _normal(
            cameraPos.rotateVector(
                baseDir,
                _fovXYZ * (
                    Entities::Transform::Vector3f(
                        x - (screenSize.getX() / 2.0),
                        0,
                        (screenSize.getY() / 2.0) - y
                    )
                )
            )
            // baseDir
            //     .rotateX(fovXYZ.getX() * (x - (screenSize.getX() / 2.0)))
            //     .rotateZ(fovXYZ.getZ() * (y - (screenSize.getY() / 2.0)))
        ),
        _ray(_cameraPos - (_normal * Entities::Transform::Vector3f(100, 100, 100)), _cameraPos)
    {
        // std::cout << _fovXYZ << std::endl;
    }

    Images::IRayIterator::IIterator &CustomRayIterator::Iterator::operator++()
    {
        auto x = _x + 1;
        auto y = _y;
        if (x >= _screenSize.getX()) {
            x = 0;
            y += 1;
        }
        auto newIter = CustomRayIterator::Iterator(_cameraPos, _screenSize, _fovXYZ, _fov, x, y);
        *this = newIter;

        return *this;
    }

    Images::Ray &CustomRayIterator::Iterator::operator*()
    {
        return _ray;
    }

    bool CustomRayIterator::Iterator::operator==(const Images::IRayIterator::IIterator &other) const
    {
        return this->toString() == other.toString();
    }

    std::string CustomRayIterator::Iterator::toString() const
    {
        return (
            std::to_string(_x) + " " +
                std::to_string(_y) + " " +
            std::to_string(_fovXYZ.getX()) + " " +
                std::to_string(_fovXYZ.getY()) + " " +
                std::to_string(_fovXYZ.getZ()) + " " +
            std::to_string(_cameraPos.getX()) + " " +
                std::to_string(_cameraPos.getY()) + " " +
                std::to_string(_cameraPos.getZ())
        );
    }

    bool CustomRayIterator::Iterator::operator!=(const Images::IRayIterator::IIterator &other) const
    {
        return !(*this == other);
    }

    CustomRayIterator::Iterator &CustomRayIterator::Iterator::operator=(const CustomRayIterator::Iterator &other)
    {
        _cameraPos = other._cameraPos;
        _screenSize = other._screenSize;
        _fovXYZ = other._fovXYZ;
        _fov = other._fov;
        _x = other._x;
        _y = other._y;
        _normal = other._normal;
        _ray = other._ray;
        return *this;
    }

    // -----------------------------------------------------------------------
    // CustomRayIterator
    // -----------------------------------------------------------------------

    CustomRayIterator::CustomRayIterator(const Entities::Transform::Vector3f &cameraPos, const Entities::Transform::Vector2i &screenSize, const Entities::Transform::Vector3f &fov, std::size_t unit):
        _cameraPos(cameraPos),
        _screenSize(screenSize),
        _fov(fov),
        _fovXYZ(
            unit * fov.getX() / screenSize.getX(),
            0,
            unit * fov.getY() / screenSize.getY()
        )
    {
        _fov = Entities::Transform::Vector3f(fov.getX(), fov.getZ(), fov.getY());
        std::cout << _fovXYZ << std::endl;
    }

    std::unique_ptr<Images::IRayIterator::IIterator> CustomRayIterator::begin() const
    {
        return std::make_unique<Iterator>(_cameraPos, _screenSize, _fovXYZ, _fov, 0, 0);
    }

    std::unique_ptr<Images::IRayIterator::IIterator> CustomRayIterator::end() const
    {
        return std::make_unique<Iterator>(_cameraPos, _screenSize, _fovXYZ, _fov, _screenSize.getX() + 1, _screenSize.getY());
    }
}
