/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SSAAx4Entity.hpp
*/

#ifndef BASICENTITY_HPP_
    #define BASICENTITY_HPP_

    #include <future>
#include <vector>
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
            /**
             * @brief Wait one place in the vector of futures
             */
            void waitOnePlace();
            /**
             * @brief Wait all places in the vector of futures
             */
            void waitAllFinisehd();
            /**
             * @brief Mean of the colors
             *
             * @param colors The colors to mean
             *
             * @return The mean
             */
            static Images::Color getColorsMean(const std::vector<Images::Color> &colors);
            ILogger &_logger;
            int _maxThread;
            std::vector<std::future<void>> _futures;
    };
}

#endif
