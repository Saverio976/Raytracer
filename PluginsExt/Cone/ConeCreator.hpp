/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeCreator.hpp
*/

#ifndef RAYTRACER_CONECREATOR_HPP
    #define RAYTRACER_CONECREATOR_HPP
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"

namespace RayTracer::PluginsExt::Cone {
    class ConeCreator : public RayTracer::Plugins::Entities::IEntityCreator  {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
    };
}

#endif //RAYTRACER_CONECREATOR_HPP
