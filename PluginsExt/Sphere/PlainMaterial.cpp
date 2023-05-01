/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.cpp
*/

#include "PlainMaterial.hpp"
#include "Color.hpp"
#include "ISetting.hpp"
#include "Ray.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"
#include "Vector3f.hpp"
#include <cmath>

namespace RayTracer::PluginsExt::Sphere {
    PlainMaterial::PlainMaterial(const Scenes::ISetting &config): _shininess(static_cast<double>(*config.get("shininess"))),
          _ambient(Images::Color(*config.get("ambient"))), _diffuse(Images::Color(*config.get("diffuse"))),
          _specular(Images::Color(*config.get("specular"))) {};

    Images::Color PlainMaterial::getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::Displayable &displayable) const
    {
        Images::Color color(0, 0, 0, 0);
        Images::Color colorRound = round(_ambient);
        Images::Color colorTmp(0, 0, 0, 0);
        Images::Color ambient(0, 0, 0, 0);
        Images::Color diffuse(0, 0, 0, 0);
        Images::Color specular(1, 1, 1, 1);
        Entities::Transform::Vector3f normal = intersect;
        Entities::Transform::Vector3f shiftedPoint(0, 0, 0);
        Entities::Transform::Vector3f intersectToLight(0, 0, 0);

        normal = (normal - centerObj.getPosition()).getNormalized();
        for (const auto &light : displayable.getLightList()) {
            ambient = round(light->getColor(intersect, displayable));
            diffuse = ambient;
            shiftedPoint = intersect + Entities::Transform::Vector3f(1e-5, 1e-5, 1e-5) * normal;
            intersectToLight = (light->getTransform().getPosition() - shiftedPoint).getNormalized();

            colorTmp = Images::Color(
                colorRound[Images::Color::Types::RED] * ambient[Images::Color::Types::RED],
                colorRound[Images::Color::Types::GREEN] * ambient[Images::Color::Types::GREEN],
                colorRound[Images::Color::Types::BLUE] * ambient[Images::Color::Types::BLUE],
                0
            );
            colorTmp = colorTmp + Images::Color(
                _diffuse[Images::Color::Types::RED] * diffuse[Images::Color::Types::RED] * intersectToLight.dot(normal),
                _diffuse[Images::Color::Types::GREEN] * diffuse[Images::Color::Types::GREEN] * intersectToLight.dot(normal),
                _diffuse[Images::Color::Types::BLUE] * diffuse[Images::Color::Types::BLUE] * intersectToLight.dot(normal),
                0
            );
            Entities::Transform::Vector3f H = (intersectToLight + ray.getDirection()).getNormalized();
            colorTmp = colorTmp + Images::Color(
                _specular[Images::Color::Types::RED] * specular[Images::Color::Types::RED] * std::pow(normal.dot(H), _shininess / 4.0),
                _specular[Images::Color::Types::GREEN] * specular[Images::Color::Types::GREEN] * std::pow(normal.dot(H), _shininess / 4.0),
                _specular[Images::Color::Types::BLUE] * specular[Images::Color::Types::BLUE] * std::pow(normal.dot(H), _shininess / 4.0),
                0
            );
            color = color + colorTmp;
        }
        return color;
    }

    void PlainMaterial::setColor(const Images::Color &color)
    {
        _ambient = color;
    }

    Images::Color PlainMaterial::round(const Images::Color &color) const
    {
        Images::Color result = color;

        result[Images::Color::Types::RED] = result[Images::Color::Types::RED] / 255.0;
        result[Images::Color::Types::GREEN] = result[Images::Color::Types::GREEN] / 255.0;
        result[Images::Color::Types::BLUE] = result[Images::Color::Types::BLUE] / 255.0;
        return result;
    }
}
