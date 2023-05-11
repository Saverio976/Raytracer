/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** BlackAndWhiteFilter.hpp
*/

#ifndef BASICENTITY_HPP_
    #define BASICENTITY_HPP_

    #include <future>
#include <string>
    #include <vector>
    #include "Color.hpp"
    #include "ILogger.hpp"
    #include "IFilter.hpp"
    #include "ISetting.hpp"
    #include "Image.hpp"

namespace RayTracer::PluginsExt::BlackAndWhite {
    class BlackAndWhiteFilter : public Filters::IFilter {
        public:
            BlackAndWhiteFilter(const Scenes::ISetting &config, ILogger &logger);
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
            static Images::Color getColorsMean(const Images::Color &color, const std::string &method);
            ILogger &_logger;
            int _maxThread;
            std::vector<std::future<void>> _futures;
            std::string _method;
    };
}

#endif
