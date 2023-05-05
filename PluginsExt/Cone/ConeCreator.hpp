/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConeCreator.hpp
*/

#ifndef RAYTRACER_CONECREATOR_HPP
    #define RAYTRACER_CONECREATOR_HPP
    #include "IEntityCreator.hpp"

namespace RayTracer::PluginsExt::Cone {
    class ConeCreator : public RayTracer::Plugins::Entities::IEntityCreator  {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;
        protected:
        private:
    };
}

#endif //RAYTRACER_CONECREATOR_HPP
