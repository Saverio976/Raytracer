/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

namespace RayTracer::Entities::Transform {
    Transform::Transform(const Scenes::ISetting &setting): _position(*setting.get("position")),
        _rotation(*setting.get("rotation")), _scale(*setting.get("scale")) {};

    const Vector3f &Transform::getPosition() const {
        return this->_position;
    }

    const Vector3f &Transform::getRotation() const {
        return this->_rotation;
    }

    const Vector3f &Transform::getScale() const {
        return this->_scale;
    }

    void Transform::setPosition(const RayTracer::Entities::Transform::Vector3f &position) {
        this->_position = position;
    }

    void Transform::setScale(const RayTracer::Entities::Transform::Vector3f &scale) {
        this->_scale = scale;
    }

    void Transform::setRotation(const RayTracer::Entities::Transform::Vector3f &rotation) {
        this->_rotation = rotation;
    }

    ITransform &Transform::operator=(const RayTracer::Entities::Transform::ITransform &other) {
        this->_rotation = other.getRotation();
        this->_scale = other.getScale();
        this->_position = other.getPosition();
        return *this;
    }
}
