/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ClusterRayIterator.cpp
*/

#include <cmath>
#include <cstddef>
#include <memory>
#include <string>
#include "ClusterRayIterator.hpp"
#include "ICamera.hpp"
#include "Ray.hpp"
#include "RayIterrator.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Camera::Clustered {
    // -----------------------------------------------------------------------
    // ClusterRayIterator::iterrator
    // -----------------------------------------------------------------------

    ClusterRayIterator::Iterator::Iterator(
            const Entities::Transform::Vector3f &cameraPos,
            const Entities::Transform::Vector2i &screenSize,
            const Entities::Transform::Vector3f &screenPosTopLeft,
            std::size_t x,
            std::size_t y,
            std::size_t cluster):
        _cameraPos(cameraPos),
        _screenSize(screenSize),
        _screenPosTopLeft(screenPosTopLeft),
        _cluster(cluster),
        _x(x),
        _y(y),
        _ray({0, 0, 0}, {0, 0, 0})
    {
        auto added = screenPosTopLeft + Entities::Transform::Vector3f(
            x + (static_cast<double>(cluster) / 2.0),
            0,
            0 - (y + (static_cast<double>(cluster) / 2.0))
        );
        _ray = Images::Ray(_cameraPos, added);
    }

    Images::IRayIterator::IIterator &ClusterRayIterator::Iterator::operator++()
    {
        auto x = _x + _cluster;
        auto y = _y;
        if (x >= _screenSize.getX()) {
            x = 0;
            y += _cluster;
        }
        auto newIter = ClusterRayIterator::Iterator(_cameraPos, _screenSize, _screenPosTopLeft, x, y, _cluster);

        *this = newIter;
        return *this;
    }

    Images::Ray &ClusterRayIterator::Iterator::operator*()
    {
        return _ray;
    }

    bool ClusterRayIterator::Iterator::operator==(const Images::IRayIterator::IIterator &other) const
    {
        return this->toString() == other.toString();
    }

    std::string ClusterRayIterator::Iterator::toString() const
    {
        return (
            std::to_string(_x) + " " +
                std::to_string(_y) + " " +
            std::to_string(_cameraPos.getX()) + " " +
                std::to_string(_cameraPos.getY()) + " " +
                std::to_string(_cameraPos.getZ())
        );
    }

    bool ClusterRayIterator::Iterator::operator!=(const Images::IRayIterator::IIterator &other) const
    {
        return !(*this == other);
    }

    ClusterRayIterator::Iterator &ClusterRayIterator::Iterator::operator=(const ClusterRayIterator::Iterator &other)
    {
        _cameraPos = other._cameraPos;
        _screenSize = other._screenSize;
        _screenPosTopLeft = other._screenPosTopLeft;
        _cluster = other._cluster;
        _x = other._x;
        _y = other._y;
        _ray = other._ray;
        return *this;
    }

    // -----------------------------------------------------------------------
    // ClusterRayIterator
    // -----------------------------------------------------------------------

    ClusterRayIterator::ClusterRayIterator(
            const Entities::Transform::Vector3f &cameraPos,
            const Entities::Transform::Vector3f &screenPosCenter,
            const Entities::Transform::Vector2i &screenSize,
            std::size_t unit):
        _cameraPos(cameraPos),
        _screenPosCenter(screenPosCenter),
        _screenSize(screenSize),
        _unit(unit)
    {
        _screenPosTopLeft = _screenPosCenter + Entities::Transform::Vector3f(
            0 - static_cast<double>(screenSize.getX()) / 2.0,
            0,
            static_cast<double>(screenSize.getY()) / 2.0
        );
    }

    std::unique_ptr<Images::IRayIterator::IIterator> ClusterRayIterator::begin() const
    {
        return std::make_unique<Iterator>(_cameraPos, _screenSize, _screenPosTopLeft, 0, 0, _unit);
    }

    std::unique_ptr<Images::IRayIterator::IIterator> ClusterRayIterator::end() const
    {
        return std::make_unique<Iterator>(_cameraPos, _screenSize, _screenPosTopLeft, _screenSize.getX() + 1, _screenSize.getY(), _unit);
    }
}
