/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** BlackAndWhiteCreator.hpp
*/

#ifndef SPHERE_CREATOR_HPP_
    #define SPHERE_CREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IFilter.hpp"
    #include "IFilterCreator.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"
    #include "BlackAndWhiteFilter.hpp"

namespace RayTracer::PluginsExt::BlackAndWhite {
    class BlackAndWhiteCreator : public Plugins::Filters::IFilterCreator {
        public:
            ~BlackAndWhiteCreator();
            Filters::IFilter *create(const Scenes::ISetting &config, ILogger &logger) final;

        private:
            std::vector<BlackAndWhiteFilter *> _elements;
    };
}

#endif
