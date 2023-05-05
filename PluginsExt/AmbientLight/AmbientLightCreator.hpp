/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightCreator.hpp
*/

#ifndef AMBIENTLIGHTCREATOR_HPP_
    #define AMBIENTLIGHTCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "AmbientLightEntity.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    class AmbientLightCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~AmbientLightCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;

        protected:
        private:
            std::vector<AmbientLightEntity *> _elements;
    };
}

#endif /*AMBIENTLIGHTCREATOR_HPP_*/
