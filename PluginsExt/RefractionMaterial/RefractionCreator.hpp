/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef REFRACTIONMATERIALCREATOR_HPP_
    #define REFRACTIONMATERIALCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "RefractionMaterial.hpp"

namespace RayTracer::PluginsExt::Refraction {
    class RefractionCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
    public:
        ~RefractionCreator();
        RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<RefractionMaterial *> _elements;
    };
}

#endif /*PLANECREATOR_HPP_*/
