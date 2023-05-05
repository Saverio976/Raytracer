/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Progress.hpp
*/

#ifndef RAYTRACER_PROGRESS_HPP
    #define RAYTRACER_PROGRESS_HPP

    #include "ILogger.hpp"

namespace RayTracer {
    class Progress {
        public:
            /**
             * @brief Construct a new Progress object
             *
             * @param max what is 100% for you ?
             * @param threshold when to prompt (0.1 = every 10% passed, 0.05 = every 5% passed)
             */
            Progress(float max, float threshold, ILogger &logger);

            /**
             * @brief Add a value
             *
             * @param value the value
             */
            void add(float value);

        private:
            ILogger &_logger;
            double _max;
            double _step;
            double _current;
            double _nextStep;
    };
}

#endif
