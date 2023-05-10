/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** RayIterrator.cpp
*/

#include "RayIterrator.hpp"
#include "ICamera.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"
#include <memory>
#include <string>

namespace RayTracer::Images {
    // -----------------------------------------------------------------------
    // RayIterrator::iterrator
    // -----------------------------------------------------------------------

    RayIterrator::Iterrator::Iterrator(const Ray &last, const Entities::Transform::Vector2i &size, const Entities::Transform::Vector3f &screenPos, const Entities::Transform::Vector3f &pov):
        _last(last), _size(size), _screenPos(screenPos), _pov(pov), _ray(last)
    {
        Entities::Transform::Vector3f right(1, 0, 0);
        Entities::Transform::Vector3f resetX(_screenPos.getX() - (size.getX() / 2.0), last.getOrigin().getY(), last.getOrigin().getZ() - 1);
        Entities::Transform::Vector3f onScreenPos(last.getOrigin().getX(), last.getOrigin().getY(), last.getOrigin().getZ());

        if (onScreenPos.getX() + right.getX() >= screenPos.getX() + (size.getX() / 2.0)) {
            onScreenPos = resetX;
        } else {
            onScreenPos = onScreenPos + right;
        }
        _ray = Ray(pov, onScreenPos, {10, 0, 0});
    }

    IRayIterator::IIterator &RayIterrator::Iterrator::operator++() {
        auto iter = RayIterrator::Iterrator(_ray, _size, _screenPos, _pov);

        *this = iter;
        return *this;
    }

    Ray &RayIterrator::Iterrator::operator*() {
        return _ray;
    }

    bool RayIterrator::Iterrator::operator==(const IRayIterator::IIterator &other) const {
        return this->toString() == other.toString();
    }

    bool RayIterrator::Iterrator::operator!=(const IRayIterator::IIterator &other) const {
        return !(*this == other);
    }

    RayIterrator::Iterrator &RayIterrator::Iterrator::operator=(const RayIterrator::Iterrator &other) {
        _ray = other._ray;
        return *this;
    }

    std::string RayIterrator::Iterrator::toString() const {
        return (
            std::to_string(_ray.getOrigin().getX()) + " " +
                std::to_string(_ray.getOrigin().getY()) + " " +
                std::to_string(_ray.getOrigin().getZ()) + " " +
            std::to_string(_ray.getDirection().getX()) + " " +
                std::to_string(_ray.getDirection().getY()) + " " +
                std::to_string(_ray.getDirection().getZ())
        );
    }

    // -----------------------------------------------------------------------
    // RayIterrator
    // -----------------------------------------------------------------------

    RayIterrator::RayIterrator(const Entities::ICamera &camera):
        _camera(camera),
        _pov(camera.getTransform().getPosition()),
        _beforeFirst(Entities::Transform::Vector3f(0, 0, 0), Entities::Transform::Vector3f(0, 0, 0)),
        _afterLast(Entities::Transform::Vector3f(0, 0, 0), Entities::Transform::Vector3f(0, 0, 0))
    {
        Entities::Transform::Vector3f update(0, 0 - camera.getFocal(), 0);
        Entities::Transform::Vector3f rayScreenPos(0 - (camera.getSize().getX() / 2.0) - 1, 0, camera.getSize().getY() / 2.0);
        Entities::Transform::Vector3f rayScreenNeg((camera.getSize().getX() / 2.0) + 1, 0, 0 - (camera.getSize().getY() / 2.0));
        Entities::Transform::Vector3f pos(camera.getTransform().getPosition());

        _pov = _pov + update;
        _beforeFirst = Ray(_pov, pos + rayScreenPos);
        _afterLast = Ray(_pov, pos + rayScreenNeg);
    }

    std::unique_ptr<IRayIterator::IIterator> RayIterrator::begin() const
    {
        auto iter = std::make_unique<RayIterrator::Iterrator>(_beforeFirst, _camera.getSize(), _camera.getTransform().getPosition(), _pov);

        return iter;
    }

    std::unique_ptr<IRayIterator::IIterator> RayIterrator::end() const
    {
        auto iter = std::make_unique<RayIterrator::Iterrator>(_afterLast, _camera.getSize(), _camera.getTransform().getPosition(), _pov);

        return iter;
    }
}
