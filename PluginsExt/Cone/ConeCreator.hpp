/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeCreator.hpp
*/

#ifndef RAYTRACER_CONECREATOR_HPP
    #define RAYTRACER_CONECREATOR_HPP

    #include <vector>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "ConeEntity.hpp"

namespace RayTracer::PluginsExt::Cone {
    class ConeCreator : public RayTracer::Plugins::Entities::IEntityCreator  {
        public:
            ~ConeCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
            std::vector<ConeEntity *> _elements;
    };
}

#endif //RAYTRACER_CONECREATOR_HPP
