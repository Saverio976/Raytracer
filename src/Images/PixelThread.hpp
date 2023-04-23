/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PixelThread.hpp
*/
#ifndef PIXELTHREAD_HPP_
    #define PIXELTHREAD_HPP_

    #include "Displayable.hpp"

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
             */
            PixelThread(const Scenes::Displayable &displayable, Color &color);
            ~PixelThread();
            /**
             * @brief The function that actualy do all the work
             */
            void operator()();

        protected:
        private:
    };
}

#endif /*PIXELTHREAD_HPP_*/
