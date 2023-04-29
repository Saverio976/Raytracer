/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlainMaterial.hpp
*/

#ifndef PLAINMATERIAL_HPP_
    #define PLAINMATERIAL_HPP_

    #include "ITransform.hpp"
    #include "Vector3f.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Sphere {
    class PlainMaterial : public Entities::IMaterial {
        public:
            PlainMaterial(const IConfig &config);

            const Images::Color &getColor(const Entities::Transform::ITransform &centerObj, const Entities::Transform::Vector3f &intersect, const Scenes::Displayable &displayable) const final;
            void setColor(const Images::Color &color) final;
    };
}

#endif
