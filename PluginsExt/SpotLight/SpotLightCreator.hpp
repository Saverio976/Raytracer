/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SpotLightCreator.hpp
*/

#ifndef SPOTLIGHTCREATOR_HPP_
    #define SPOTLIGHTCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "ILogger.hpp"
    #include "IEntityCreator.hpp"
    #include "SpotLightEntity.hpp"

namespace RayTracer::PluginsExt::SpotLight {
    class SpotLightCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        ~SpotLightCreator();

    protected:
    private:
        std::vector<SpotLightEntity *> _elements;
    };
}

#endif
