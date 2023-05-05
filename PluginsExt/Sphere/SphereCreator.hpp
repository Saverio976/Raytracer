/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.hpp
*/

#ifndef SPHERE_CREATOR_HPP_
    #define SPHERE_CREATOR_HPP_

    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"

namespace RayTracer::PluginsExt::Sphere {
    class SphereCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    };
}

#endif
