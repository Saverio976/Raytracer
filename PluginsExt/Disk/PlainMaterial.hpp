/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.hpp
*/

#ifndef PLAINMATERIAL_HPP_
#define PLAINMATERIAL_HPP_

#include "ISetting.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "ITransform.hpp"
#include "Vector3f.hpp"
#include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Disk {
    class PlainMaterial : public Entities::IMaterial {
    public:
        PlainMaterial(const Scenes::ISetting &config);

        Images::Color getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const final;
        void setColor(const Images::Color &color) final;

        Images::Color round(const Images::Color &color) const;
    private:
        Images::Color _color;
        double _shininess;
    };
}

#endif
