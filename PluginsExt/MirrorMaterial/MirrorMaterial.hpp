/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.hpp
*/

#ifndef MIRRORMATERIAL_HPP_
    #define MIRRORMATERIAL_HPP_

    #include "ISetting.hpp"
    #include "Ray.hpp"
    #include "Color.hpp"
    #include "ITransform.hpp"
    #include "Vector3f.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Mirror {
    class MirrorMaterial : public Entities::IMaterial {
    public:
        MirrorMaterial(const Scenes::ISetting &config);

        Images::Color getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const final;
        void setColor(const Images::Color &color) final;
        Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
            const Entities::Transform::Vector3f &intersect) const final;

    private:
        Images::Color getNextColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const;
        Images::Color _color;
        Entities::Transform::Vector3f _ambient;
        Entities::Transform::Vector3f _diffuse;
        Entities::Transform::Vector3f _specular;
        double _shininess;
        double _transparency;
    };
}

#endif
