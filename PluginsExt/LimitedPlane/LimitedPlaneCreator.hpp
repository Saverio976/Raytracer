/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedPlaneCreator.hpp
*/

#ifndef LIMITEDPLANECREATOR_HPP_
	#define LIMITEDPLANECREATOR_HPP_
    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "LimitedPlaneEntity.hpp"

namespace RayTracer::PluginsExt::LimitedPlane {
    class LimitedPlaneCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        ~LimitedPlaneCreator();
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<LimitedPlaneEntity *> _elements;
    };
}

#endif /*LIMITEDPLANECREATOR_HPP_*/