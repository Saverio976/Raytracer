/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef PLANECREATOR_HPP_
    #define PLANECREATOR_HPP_

    #include "IEntityCreator.hpp"
#include "ILogger.hpp"

namespace RayTracer::PluginsExt::Plane {
    class PlaneCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
    };
}

#endif /*PLANECREATOR_HPP_*/
