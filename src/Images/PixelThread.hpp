/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PixelThread.hpp
*/
#ifndef PIXELTHREAD_HPP_
    #define PIXELTHREAD_HPP_

    #include "IDisplayable.hpp"
    #include "Ray.hpp"
    #include "Color.hpp"

namespace RayTracer::Images {
    /**
     * @brief The PixelThread class
     *
     * class that represent a ray pixel calcul
     */
    class PixelThread {
        public:
            /**
             * @brief PixelThread constructor (this doesn't do anything)
             *
             * @param displayable the displayable to calcul
             * @param color the color to modify
             * @param ray the ray
             */
            PixelThread(const Scenes::IDisplayable &displayable, Color &color, const Images::Ray &ray);
            ~PixelThread() = default;
            /**
             * @brief The function that actualy do all the work
             */
            void operator()();

        protected:
        private:
            const Scenes::IDisplayable &_displayable;
            Color &_color;
            Images::Ray _ray;
    };
}

#endif /*PIXELTHREAD_HPP_*/
