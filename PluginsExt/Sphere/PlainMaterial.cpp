/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.cpp
*/

#include <cmath>
#include "PlainMaterial.hpp"
#include "Color.hpp"
#include "ISetting.hpp"
#include "Ray.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Sphere {
    PlainMaterial::PlainMaterial(const Scenes::ISetting &config):
        _shininess(static_cast<double>(*config.get("shininess"))),
        _color(Images::Color(*config.get("color")))
    {
    }

    Images::Color PlainMaterial::getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const
    {
        double r = 0;
        double g = 0;
        double b = 0;
        Images::Color rounded = this->round(this->_color);
        size_t size = displayable.getLightList().size() + 1;
        Images::Color color(0, 0, 0, 255);

        if (size == 1)
            return {0, 0, 0, 0};
        for (const std::reference_wrapper<Entities::ILight> &light : displayable.getLightList()) {
            color = light.get().getColor(intersect, displayable);
            double coef = 0;
            if (light.get().isAmbient()) {
                coef = 1;
            } else {
                coef = (intersect - centerObj.getPosition()).getNormalized().dot(intersect - light.get().getTransform().getPosition());
                if (coef == 0) {
                    coef = 3;
                } else {
                    coef = std::pow((std::log(std::abs(coef)) - (3.4 - _shininess)) * light.get().getPower(), (std::log(std::abs(coef)) - (3.4 - _shininess)));
                }
                if (coef < 0) {
                    coef = 0;
                }
            }
            r += color[Images::Color::Types::RED] * coef * rounded[Images::Color::Types::RED];
            g += color[Images::Color::Types::GREEN] * coef * rounded[Images::Color::Types::GREEN];
            b += color[Images::Color::Types::BLUE] * coef * rounded[Images::Color::Types::BLUE];
        }
        r /= size;
        g /= size;
        b /= size;
        color = this->round(Images::Color(r, g, b, 255)) * Images::Color(255, 255, 255, 255);
        return color;
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
