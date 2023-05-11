/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef CHESSBOARDCREATOR_HPP_
    #define CHESSBOARDCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "ZebraMaterial.hpp"

namespace RayTracer::PluginsExt::Zebra {
    class ZebraCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
    public:
        ~ZebraCreator();
        RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<ZebraMaterial *> _elements;
    };
}

#endif
