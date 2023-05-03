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

namespace RayTracer::Images {
    // -----------------------------------------------------------------------
    // RayIterrator::iterrator
    // -----------------------------------------------------------------------

    RayIterrator::iterrator::iterrator(const Ray &last, const Entities::Transform::Vector2i &size, const Entities::Transform::Vector3f &screenPos, const Entities::Transform::Vector3f &pov):
        _last(last), _size(size), _screenPos(screenPos), _pov(pov), _ray(last)
    {
        Entities::Transform::Vector3f right(1, 0, 0);
        Entities::Transform::Vector3f down(0, -1, 0);
        Entities::Transform::Vector3f resetX(size.getX(), 0, 0);
        Entities::Transform::Vector3f onScreenPos(last.getOrigin().getX(), last.getOrigin().getY(), last.getOrigin().getZ());

        if (onScreenPos.getX() + right.getX() >= screenPos.getX() + (size.getX() / 2.0)) {
            onScreenPos = onScreenPos + down;
            onScreenPos = onScreenPos - resetX;
        } else {
            onScreenPos = onScreenPos + right;
        }
        _ray = Ray(pov, onScreenPos);
    }

    RayIterrator::iterrator RayIterrator::iterrator::operator++() {
        auto iter = RayIterrator::iterrator(_ray, _size, _screenPos, _pov);

        return iter;
    }

    Ray RayIterrator::iterrator::operator*() {
        return _ray;
    }

    bool RayIterrator::iterrator::operator==(const RayIterrator::iterrator &other) const {
        bool isEq = _ray.getOrigin().getX() == other._ray.getOrigin().getX() &&
                    _ray.getOrigin().getY() == other._ray.getOrigin().getY() &&
                    _ray.getOrigin().getZ() == other._ray.getOrigin().getZ();
        isEq = isEq &&
                    _ray.getDirection().getX() == other._ray.getDirection().getX() &&
                    _ray.getDirection().getY() == other._ray.getDirection().getY() &&
                    _ray.getDirection().getZ() == other._ray.getDirection().getZ();
        return isEq;
    }

    bool RayIterrator::iterrator::operator!=(const RayIterrator::iterrator &other) const {
        return !(*this == other);
    }

    RayIterrator::iterrator &RayIterrator::iterrator::operator=(const RayIterrator::iterrator &other) {
        _ray = other._ray;
        return *this;
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
        Entities::Transform::Vector3f update(0, 0, 0 - camera.getFocal());
        Entities::Transform::Vector3f rayScreenPos(0 - (camera.getSize().getX() / 2.0) - 1, camera.getSize().getY() / 2.0, 0);
        Entities::Transform::Vector3f rayScreenNeg((camera.getSize().getX() / 2.0) + 1, 0 - (camera.getSize().getY() / 2.0), 0);
        Entities::Transform::Vector3f pos(camera.getTransform().getPosition());

        _pov = _pov + update;
        _beforeFirst = Ray(_pov, pos + rayScreenPos);
        _afterLast = Ray(_pov, pos + rayScreenNeg);
    }

    RayIterrator::iterrator RayIterrator::begin() const
    {
        auto iter = RayIterrator::iterrator(_beforeFirst, _camera.getSize(), _camera.getTransform().getPosition(), _pov);

        return iter;
    }

    RayIterrator::iterrator RayIterrator::end() const
    {
        auto iter = RayIterrator::iterrator(_afterLast, _camera.getSize(), _camera.getTransform().getPosition(), _pov);

        return iter;
    }
}
