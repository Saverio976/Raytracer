/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef MIRRORMATERIALCREATOR_HPP_
    #define MIRRORMATERIALCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "MirrorMaterial.hpp"

namespace RayTracer::PluginsExt::Mirror {
    class MirrorCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
    public:
        ~MirrorCreator();
        RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<MirrorMaterial *> _elements;
    };
}

#endif /*PLANECREATOR_HPP_*/
