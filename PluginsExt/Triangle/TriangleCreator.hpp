/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TriangleCreator.hpp
*/

#ifndef TRIANGLECREATOR_HPP_
	#define TRIANGLECREATOR_HPP_
    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "TriangleEntity.hpp"

namespace RayTracer::PluginsExt::Triangle {
    class TriangleCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        ~TriangleCreator();
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<TriangleEntity *> _elements;
    };
}

#endif /*TRIANGLECREATOR_HPP_*/