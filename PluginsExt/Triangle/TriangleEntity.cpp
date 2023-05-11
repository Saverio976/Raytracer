/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TriangleEntity.cpp
*/
#include "ILogger.hpp"
#include "TriangleEntity.hpp"
#include "IMaterialFactory.hpp"
#include "Vector2i.hpp"

namespace RayTracer::PluginsExt::Triangle {
    TriangleEntity::TriangleEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _logger(logger),
        _pointOne(*config.get("pointOne")),
        _pointTwo(*config.get("pointTwo")),
        _pointThree(*config.get("pointThree"))
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));
    }

    Entities::IEntity::Type TriangleEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &TriangleEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &TriangleEntity::getTransform() const {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> TriangleEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();
        Entities::Transform::Vector3f edgeOne = _pointTwo - _pointOne;
        Entities::Transform::Vector3f edgeTwo = _pointThree - _pointOne;
        Entities::Transform::Vector3f normal = edgeOne.getCrossed(edgeTwo).getNormalized();
        Entities::Transform::Vector3f pointOneRayOrigin(_pointOne.getX() - rayOrigin.getX(), _pointOne.getY() - rayOrigin.getY(), _pointOne.getZ() - rayOrigin.getZ());

        double denominator = normal.dot(rayDirection);
        if (std::abs(denominator) < std::numeric_limits<float>::epsilon())
            return std::nullopt;
        double numerator = normal.dot(pointOneRayOrigin);
        double t = numerator / denominator;

        if (t < 0)
            return std::nullopt;
        Entities::Transform::Vector3f point = rayOrigin + rayDirection * Entities::Transform::Vector3f(t, t, t);

        Entities::Transform::Vector3f collisionEdgeOne = _pointTwo - _pointOne;
        Entities::Transform::Vector3f crossedCollisionEdgeOne = collisionEdgeOne.getCrossed(point - _pointOne);
        if (normal.dot(crossedCollisionEdgeOne) < 0)
            return std::nullopt;
        Entities::Transform::Vector3f collisionEdgeTwo = _pointThree - _pointTwo;
        Entities::Transform::Vector3f crossedCollisionEdgeTwo = collisionEdgeTwo.getCrossed(point - _pointTwo);
        if (normal.dot(crossedCollisionEdgeTwo) < 0)
            return std::nullopt;
        Entities::Transform::Vector3f collisionEdgeThree = _pointOne - _pointThree;
        Entities::Transform::Vector3f crossedCollisionEdgeThree = collisionEdgeThree.getCrossed(point - _pointThree);
        if (normal.dot(crossedCollisionEdgeThree) < 0)
            return std::nullopt;
        return point;
    }

    bool TriangleEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color TriangleEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        Entities::Transform::Vector3f edgeOne = _pointTwo - _pointOne;
        Entities::Transform::Vector3f edgeTwo = _pointThree - _pointOne;
        Entities::Transform::Vector3f normal = edgeOne.getCrossed(edgeTwo).getNormalized();
        Entities::Transform::Transform transform = _transform;
        transform.setPosition(intersect - normal);
        return _material->get().getColor(ray, transform, intersect, displayable);
    }

    Images::Color TriangleEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
