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
    PlainMaterial::PlainMaterial(const Scenes::ISetting &config):
        _shininess(static_cast<double>(*config.get("shininess"))),
        _color(Images::Color(*config.get("color")))
    {
    }

    Images::Color PlainMaterial::getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::Displayable &displayable) const
    {
        Images::Color coefs(0, 0, 0, 0);
        double coefsTmp = 0;
        Images::Color colorLight(0, 0, 0, 0);

        for (const auto &light : displayable.getLightList()) {
            colorLight = light->getColor(intersect, displayable);

            coefsTmp = Images::Ray(ray.getOrigin(), centerObj.getPosition()).getDirection().dot(ray.getDirection()) * (_shininess / 3.0);
            coefs = coefs + (colorLight * Images::Color(coefsTmp, coefsTmp, coefsTmp, 255));
        }
        return _color * coefs;
    }

    void PlainMaterial::setColor(const Images::Color &color)
    {
        _color = color;
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
