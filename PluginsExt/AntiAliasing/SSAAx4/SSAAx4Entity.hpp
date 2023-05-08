/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SSAAx4Entity.hpp
*/

#ifndef BASICENTITY_HPP_
    #define BASICENTITY_HPP_

    #include "Color.hpp"
    #include "ILogger.hpp"
    #include "IFilter.hpp"
    #include "ISetting.hpp"
    #include "Image.hpp"

namespace RayTracer::PluginsExt::AntiAliasing::SSAAx4 {
    class SSAAx4Entity : public Filters::IFilter {
        public:
            SSAAx4Entity(const Scenes::ISetting &config, ILogger &logger);
            void apply(Images::Image &image) final;

        private:
            Images::Color getPixelMean(const Images::Image *image, const Entities::Transform::Vector2i &pos) const;
            Images::Color getPixelsReduceMean(const Images::Image *image, const Entities::Transform::Vector2i &pos) const;
            ILogger &_logger;
    };
}

#endif
