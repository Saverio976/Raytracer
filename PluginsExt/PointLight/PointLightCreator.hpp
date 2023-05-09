/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightCreator.hpp
*/

#ifndef POINTLIGHTCREATOR_HPP_
    #define POINTLIGHTCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "ILogger.hpp"
    #include "IEntityCreator.hpp"
    #include "PointLightEntity.hpp"

namespace RayTracer::PluginsExt::PointLight {
    class PointLightCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        ~PointLightCreator();

    protected:
    private:
        std::vector<PointLightEntity *> _elements;
    };
}

#endif
