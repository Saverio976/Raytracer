/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef PLAINMATERIALCREATOR_HPP_
    #define PLAINMATERIALCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "PlainMaterial.hpp"

namespace RayTracer::PluginsExt::PlainMaterial {
    class PlainMaterialCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
        public:
            ~PlainMaterialCreator();
            RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
            std::vector<PlainMaterial *> _elements;
    };
}

#endif /*PLANECREATOR_HPP_*/
