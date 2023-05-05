/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereCreator.hpp
*/

#ifndef SPHERE_CREATOR_HPP_
    #define SPHERE_CREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ISetting.hpp"
    #include "SphereEntity.hpp"

namespace RayTracer::PluginsExt::Sphere {
    class SphereCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~SphereCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;

        private:
            std::vector<SphereEntity *> _elements;
    };
}

#endif
