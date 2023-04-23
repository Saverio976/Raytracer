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
    class PixelThread {
        public:
            PixelThread(const Scenes::Displayable &displayable, Color &color);
            ~PixelThread();
            void operator()();

        protected:
        private:
    };
}

#endif /*PIXELTHREAD_HPP_*/
