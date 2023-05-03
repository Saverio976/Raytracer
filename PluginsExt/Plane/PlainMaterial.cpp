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

namespace RayTracer::PluginsExt::Plane {
    PlainMaterial::PlainMaterial(const Scenes::ISetting &config):
            _shininess(static_cast<double>(*config.get("shininess"))),
            _color(Images::Color(*config.get("color")))
    { }

    Images::Color PlainMaterial::getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::Displayable &displayable) const
    {
        double r = 0;
        double g = 0;
        double b = 0;
        size_t size = displayable.getLightList().size() + 1;
        Images::Color color = _color;

        if (size == 1)
            return {0, 0, 0, 0};
        for (const std::unique_ptr<Entities::ILight> &light : displayable.getLightList()) {
            color = light->getColor(intersect, displayable);
            r += color[Images::Color::Types::RED];
            g += color[Images::Color::Types::GREEN];
            b += color[Images::Color::Types::BLUE];
        }
        r /= size;
        g /= size;
        b /= size;
        return {r, g, b, 255};
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