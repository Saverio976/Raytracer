/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** BasicCreator.hpp
*/

#ifndef SPHERE_CREATOR_HPP_
    #define SPHERE_CREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IFilter.hpp"
    #include "IFilterCreator.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"
    #include "SSAAx4Entity.hpp"

namespace RayTracer::PluginsExt::AntiAliasing::SSAAx4 {
    class SSAAx4Creator : public Plugins::Filters::IFilterCreator {
        public:
            ~SSAAx4Creator();
            Filters::IFilter *create(const Scenes::ISetting &config, ILogger &logger) final;

        private:
            std::vector<SSAAx4Entity *> _elements;
    };
}

#endif
