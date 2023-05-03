/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef PLANECREATOR_HPP_
    #define PLANECREATOR_HPP_

    #include "IEntityCreator.hpp"

namespace RayTracer::PluginsExt::Plane {
    class PlaneCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;
        protected:
        private:
    };
}

#endif /*PLANECREATOR_HPP_*/