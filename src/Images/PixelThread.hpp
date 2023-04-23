/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PixelThread.hpp
*/
#ifndef PIXELTHREAD_HPP_
	#define PIXELTHREAD_HPP_

    #include "Displayable.hpp"

class PixelThread {
	public:
		PixelThread(const Displayable &displayable, Scenes::Color &color);
		~PixelThread();
        void operator()();

	protected:
	private:
};

#endif /*PIXELTHREAD_HPP_*/
