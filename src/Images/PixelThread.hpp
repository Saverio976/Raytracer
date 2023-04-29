/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PixelThread.hpp
*/
#ifndef PIXELTHREAD_HPP_
    #define PIXELTHREAD_HPP_

    #include "Displayable.hpp"
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
            PixelThread(const Scenes::Displayable &displayable, Color &color, const Images::Ray &ray);
            ~PixelThread();
            /**
             * @brief The function that actualy do all the work
             */
            void operator()();

        protected:
        private:
            const Scenes::Displayable &_displayable;
            Color &_color;
            Images::Ray _ray;
    };
}

#endif /*PIXELTHREAD_HPP_*/
