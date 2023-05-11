/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ChessBoardMaterial.hpp
*/

#ifndef CHESSBOARDMATERIAL_HPP_
    #define CHESSBOARDMATERIAL_HPP_

    #include "ISetting.hpp"
    #include "Ray.hpp"
    #include "Color.hpp"
    #include "ITransform.hpp"
    #include "Vector3f.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Zebra {
    class ZebraMaterial : public Entities::IMaterial {
    public:
        ZebraMaterial(const Scenes::ISetting &config);

        Images::Color getColor(const Images::Ray &ray, const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::IDisplayable &displayable) const final;
        void setColor(const Images::Color &color) final;
        Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
            const Entities::Transform::Vector3f &intersect) const final;

    private:
        Entities::Transform::Vector3f _ambient;
        Entities::Transform::Vector3f _diffuse;
        Entities::Transform::Vector3f _specular;
        double _shininess;
        Images::Color _pair;
        Images::Color _impair;
        double _size;
    };
}

#endif
