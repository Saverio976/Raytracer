/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef PLANECREATOR_HPP_
    #define PLANECREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "PlaneEntity.hpp"

namespace RayTracer::PluginsExt::Plane {
    class PlaneCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~PlaneCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
            std::vector<PlaneEntity *> _elements;
    };
}

#endif /*PLANECREATOR_HPP_*/
