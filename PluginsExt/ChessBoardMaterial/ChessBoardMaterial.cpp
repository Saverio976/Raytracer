/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.cpp
*/

#include <cmath>
#include "ChessBoardMaterial.hpp"
#include "Color.hpp"
#include "ISetting.hpp"
#include "Ray.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::ChessBoard {
    ChessBoardMaterial::ChessBoardMaterial(const Scenes::ISetting &config):
        _impair(Images::Color(*config.get("impair"))),
        _pair(Images::Color(*config.get("pair"))),
        _size(*config.get("size")),
        _shininess(*config.get("shininess")),
        _ambient(Entities::Transform::Vector3f(*config.get("ambient"))),
        _diffuse(Entities::Transform::Vector3f(*config.get("diffuse"))),
        _specular(Entities::Transform::Vector3f(*config.get("specular")))
    { }

    Images::Color ChessBoardMaterial::getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const
    {
        int boardX = intersect.getX() / this->_size;
        int boardY = intersect.getY() / this->_size;
        int boardZ = intersect.getZ() / this->_size;
        int result = boardX + boardY;
        Entities::Transform::Vector3f normal = (intersect - centerObj.getPosition()).getNormalized();
        size_t size = displayable.getLightList().size();
        Images::Color color(0, 0, 0, 255);
        double r = 0;
        double g = 0;
        double b = 0;

        if (size == 1)
            return {0, 0, 0, 0};
        for (const std::reference_wrapper<Entities::ILight> &light : displayable.getLightList()) {
            color = light.get().getColor(intersect, displayable);
            if (light.get().isAmbient()) {
                r += color[Images::Color::Types::RED] * light.get().getPower();
                g += color[Images::Color::Types::GREEN] * light.get().getPower();
                b += color[Images::Color::Types::BLUE] * light.get().getPower();
                continue;
            }
            Entities::Transform::Vector3f lightNormal = (light.get().getTransform().getPosition() - intersect).getNormalized();
            Entities::Transform::Vector3f cameraNormal = ray.getDirection().getNormalized();

            double dot = 2 * (normal.getX() * lightNormal.getX() + normal.getY() * lightNormal.getY() + normal.getZ() * lightNormal.getZ());
            Entities::Transform::Vector3f reflexionNormal = Entities::Transform::Vector3f(
                    lightNormal.getX() - dot * normal.getX(),
                    lightNormal.getY() - dot * normal.getY(),
                    lightNormal.getZ() - dot * normal.getZ()).getNormalized();

            double ar = _ambient.getX() * color[Images::Color::Types::RED];
            double ag = _ambient.getY() * color[Images::Color::Types::GREEN];
            double ab = _ambient.getZ() * color[Images::Color::Types::BLUE];

            dot = normal.getX() * lightNormal.getX() + normal.getY() * lightNormal.getY() + normal.getZ() * lightNormal.getZ();
            double dr = _diffuse.getX() * color[Images::Color::Types::RED] * dot;
            double dg = _diffuse.getY() * color[Images::Color::Types::GREEN] * dot;
            double db = _diffuse.getZ() * color[Images::Color::Types::BLUE] * dot;

            dot = reflexionNormal.getX() * cameraNormal.getX() + reflexionNormal.getY() * cameraNormal.getY() + reflexionNormal.getZ() * cameraNormal.getZ();
            double sr = _specular.getX() * color[Images::Color::Types::RED] * pow(dot, _shininess);
            double sg = _specular.getY() * color[Images::Color::Types::GREEN] * pow(dot, _shininess);
            double sb = _specular.getZ() * color[Images::Color::Types::BLUE] * pow(dot, _shininess);

            r += (ar + dr + sr) * light.get().getPower();
            g += (ag + dg + sg) * light.get().getPower();
            b += (ab + db + sb) * light.get().getPower();
        }
        r /= size;
        g /= size;
        b /= size;
        color = Images::Color(r, g, b, 255);
        color.mergeColor( (result % 2) ? this->_impair : this->_pair);
        return color;
    }

    void ChessBoardMaterial::setColor(const Images::Color &color)
    {
        _pair = color;
    }

    Images::Color ChessBoardMaterial::redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
        const Entities::Transform::Vector3f &intersect) const {
        return {0, 0, 0, 0};
    }
}
