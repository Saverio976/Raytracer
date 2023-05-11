/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjEntity.cpp
*/

#include "ILogger.hpp"
#include "ObjEntity.hpp"
#include "IMaterialFactory.hpp"
#include "Vector2i.hpp"

namespace RayTracer::PluginsExt::Obj {

    ObjEntity::Face::Face(std::string &faceString) {
        std::istringstream lineStream(faceString);
        int value = 0;

        int nb_spaces = 0;
        for (int i = 0; lineStream.str()[i]; i++)
            nb_spaces += lineStream.str()[i] == ' ' ? 1 : 0;
        lineStream.ignore();
        for (int i = 0; i < nb_spaces; i++) {
            std::string facePart;
            lineStream >> facePart;
            std::istringstream faceStringStream(facePart);
            faceStringStream >> value;
            _points.push_back(value);
            faceStringStream.ignore();
            faceStringStream >> value;
            _textures.push_back(value);
            faceStringStream.ignore();
            faceStringStream >> value;
            _normals.push_back(value);
            _size++;
        }
    }

    ObjEntity::Face::Face(int firstPoint, int secondPoint, int thirdPoint, int firstNormal, int secondNormal,
        int thirdNormal) {
        _points.push_back(firstPoint);
        _points.push_back(secondPoint);
        _points.push_back(thirdPoint);
        _normals.push_back(firstNormal);
        _normals.push_back(secondNormal);
        _normals.push_back(thirdNormal);
        _size = 3;
    }

    const std::vector<int> &ObjEntity::Face::getNormalsIndexes() const {
        return _normals;
    }

    const std::vector<int> &ObjEntity::Face::getPointsIndexes() const {
        return _points;
    }

    ObjEntity::ObjEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("material");

        std::string nameMaterial = static_cast<std::string>(*settingWrapper->get("type"));
        _material = static_cast<Entities::IMaterial &>(getMaterialFactoryInstance()->get(nameMaterial, *settingWrapper, _logger));

        std::string filePath = static_cast<std::string>(*config.get("filePath"));
        std::ifstream file(filePath);

        if (!file.good())
            return;
        std::string line;
        double x, y, z;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string prefix;

            lineStream >> prefix;
            if (prefix == "v") {
                lineStream >> x >> y >> z;
                _pointList.emplace_back(x, y, z);
            } else if (prefix == "vn") {
                lineStream >> x >> y >> z;
                _normalList.emplace_back(x, y, z);
            } else if (prefix == "f") {
                _faceList.emplace_back(line);
            }
        }
        for (const auto &face : _faceList) {
            triangulatePolygon(face);
        }
    }

    void ObjEntity::triangulatePolygon(Face face) {
        int size = face._size;
        std::vector<int> pointIndexes = face.getPointsIndexes();
        std::vector<int> normalIndexes = face.getNormalsIndexes();

        if (face._size < 3)
            return;
        if (face._size == 3) {
            _triangleList.push_back(face);
            return;
        }

        int firstNormal = normalIndexes[0];
        int firstPoint = pointIndexes[0];
        for (size_t i = 1; i < size - 1; i++) {
            int secondNormal = normalIndexes[i];
            int thirdNormal = normalIndexes[i + 1];
            int secondPoint = pointIndexes[i];
            int thirdPoint = pointIndexes[i + 1];

            _triangleList.emplace_back(firstPoint, secondPoint, thirdPoint, firstNormal, secondNormal, thirdNormal);
        }
    }

    Entities::IEntity::Type ObjEntity::getType() const {
        return Type::Primitive;
    }

    Entities::Transform::ITransform &ObjEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &ObjEntity::getTransform() const {
        return this->_transform;
    }

    std::optional<Entities::Transform::Vector3f> ObjEntity::isCollided(const Images::Ray &ray) const {
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();

        for (const auto &triangle : _triangleList) {
            std::vector<int> pointIndexes = triangle.getPointsIndexes();

            Entities::Transform::Vector3f pointOne = _pointList[pointIndexes[0] - 1];
            Entities::Transform::Vector3f pointTwo = _pointList[pointIndexes[1] - 1];
            Entities::Transform::Vector3f pointThree = _pointList[pointIndexes[2] - 1];

            Entities::Transform::Vector3f edgeOne = pointTwo - pointOne;
            Entities::Transform::Vector3f edgeTwo = pointThree - pointOne;
            Entities::Transform::Vector3f normal = edgeOne.getCrossed(edgeTwo).getNormalized();
            Entities::Transform::Vector3f pointOneRayOrigin(pointOne.getX() - rayOrigin.getX(), pointOne.getY() - rayOrigin.getY(), pointOne.getZ() - rayOrigin.getZ());

            double denominator = normal.dot(rayDirection);
            if (std::abs(denominator) < std::numeric_limits<float>::epsilon())
                continue;
            double numerator = normal.dot(pointOneRayOrigin);
            double t = numerator / denominator;

            if (t < 0)
                continue;
            Entities::Transform::Vector3f point = rayOrigin + rayDirection * Entities::Transform::Vector3f(t, t, t);

            Entities::Transform::Vector3f collisionEdgeOne = pointTwo - pointOne;
            Entities::Transform::Vector3f crossedCollisionEdgeOne = collisionEdgeOne.getCrossed(point - pointOne);
            if (normal.dot(crossedCollisionEdgeOne) < 0)
                continue;
            Entities::Transform::Vector3f collisionEdgeTwo = pointThree - pointTwo;
            Entities::Transform::Vector3f crossedCollisionEdgeTwo = collisionEdgeTwo.getCrossed(point - pointTwo);
            if (normal.dot(crossedCollisionEdgeTwo) < 0)
                continue;
            Entities::Transform::Vector3f collisionEdgeThree = pointOne - pointThree;
            Entities::Transform::Vector3f crossedCollisionEdgeThree = collisionEdgeThree.getCrossed(point - pointThree);
            if (normal.dot(crossedCollisionEdgeThree) < 0)
                continue;
            return point;
        }
        return std::nullopt;
    }

    bool ObjEntity::isCollided(const Entities::Transform::Vector3f &point) const {
        return false;
    }

    Images::Color ObjEntity::getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const
    {
        const Entities::Transform::Vector3f &rayOrigin = ray.getOrigin();
        const Entities::Transform::Vector3f &rayDirection = ray.getDirection();

        for (const auto &triangle : _triangleList) {
            std::vector<int> pointIndexes = triangle.getPointsIndexes();
            std::vector<int> normalIndexes = triangle.getNormalsIndexes();

            Entities::Transform::Vector3f pointOne = _pointList[pointIndexes[0] - 1];
            Entities::Transform::Vector3f pointTwo = _pointList[pointIndexes[1] - 1];
            Entities::Transform::Vector3f pointThree = _pointList[pointIndexes[2] - 1];

            Entities::Transform::Vector3f edgeOne = pointTwo - pointOne;
            Entities::Transform::Vector3f edgeTwo = pointThree - pointOne;
            Entities::Transform::Vector3f normal = edgeOne.getCrossed(edgeTwo).getNormalized();
            Entities::Transform::Vector3f pointOneRayOrigin(pointOne.getX() - rayOrigin.getX(), pointOne.getY() - rayOrigin.getY(), pointOne.getZ() - rayOrigin.getZ());

            double denominator = normal.dot(rayDirection);
            if (std::abs(denominator) < std::numeric_limits<float>::epsilon())
                continue;
            double numerator = normal.dot(pointOneRayOrigin);
            double t = numerator / denominator;

            if (t < 0)
                continue;
            Entities::Transform::Vector3f point = rayOrigin + rayDirection * Entities::Transform::Vector3f(t, t, t);

            Entities::Transform::Vector3f collisionEdgeOne = pointTwo - pointOne;
            Entities::Transform::Vector3f crossedCollisionEdgeOne = collisionEdgeOne.getCrossed(point - pointOne);
            if (normal.dot(crossedCollisionEdgeOne) < 0)
                continue;
            Entities::Transform::Vector3f collisionEdgeTwo = pointThree - pointTwo;
            Entities::Transform::Vector3f crossedCollisionEdgeTwo = collisionEdgeTwo.getCrossed(point - pointTwo);
            if (normal.dot(crossedCollisionEdgeTwo) < 0)
                continue;
            Entities::Transform::Vector3f collisionEdgeThree = pointOne - pointThree;
            Entities::Transform::Vector3f crossedCollisionEdgeThree = collisionEdgeThree.getCrossed(point - pointThree);
            if (normal.dot(crossedCollisionEdgeThree) < 0)
                continue;
            Entities::Transform::Transform transform = _transform;
            transform.setPosition(intersect - normal);
            return _material->get().getColor(ray, transform, intersect, displayable);
        }
        return _material->get().getColor(ray, _transform, intersect, displayable);
    }

    Images::Color ObjEntity::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return _material->get().redirectionLight(ray, displayable, intersect);
    }
}
