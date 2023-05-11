/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef TRANSPARENCYMATERIALCREATOR_HPP_
    #define TRANSPARENCYMATERIALCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "TransparencyMaterial.hpp"

namespace RayTracer::PluginsExt::Transparency {
    class TransparencyCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
    public:
        ~TransparencyCreator();
        RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<TransparencyMaterial *> _elements;
    };
}

#endif /*PLANECREATOR_HPP_*/
