/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedConeCreator.hpp
*/

#ifndef LIMITEDCONECREATOR_HPP_
	#define LIMITEDCONECREATOR_HPP_

#include <vector>
#include "IEntityCreator.hpp"
#include "ILogger.hpp"
#include "LimitedConeEntity.hpp"

namespace RayTracer::PluginsExt::LimitedCone {
    class LimitedConeCreator : public RayTracer::Plugins::Entities::IEntityCreator  {
    public:
        ~LimitedConeCreator();
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<LimitedConeEntity *> _elements;
    };
}

#endif /*LIMITEDCONECREATOR_HPP_*/