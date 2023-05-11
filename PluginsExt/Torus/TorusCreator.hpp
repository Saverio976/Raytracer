/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** TorusCreator.hpp
*/

#ifndef RAYTRACER_TORUSCREATOR_HPP
    #define RAYTRACER_TORUSCREATOR_HPP
    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "TorusEntity.hpp"

namespace RayTracer::PluginsExt::Torus {
    class TorusCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        ~TorusCreator();
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<TorusEntity *> _elements;
    };
}

#endif //RAYTRACER_TORUSCREATOR_HPP
