/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.hpp
*/

#ifndef AMBIENTLIGHTCREATOR_HPP_
    #define AMBIENTLIGHTCREATOR_HPP_

    #include "IEntityCreator.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    class AmbientLightCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;

        protected:
        private:
    };
}

#endif /*AMBIENTLIGHTCREATOR_HPP_*/
