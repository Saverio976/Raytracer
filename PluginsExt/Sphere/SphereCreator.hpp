/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.hpp
*/

#ifndef SPHERE_CREATOR_HPP_
    #define SPHERE_CREATOR_HPP_

    #include "IEntityCreator.hpp"

namespace RayTracer::PluginsExt::Sphere {
    class SphereCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            std::unique_ptr<RayTracer::Entities::IEntity> create(const IConfig &config) final;
    };
}

#endif
