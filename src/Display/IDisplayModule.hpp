/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IDisplayModule.hpp
*/
#ifndef IDISPLAYMODULE_HPP_
	#define IDISPLAYMODULE_HPP_

    #include <SFML/Graphics.hpp>

namespace RayTracer::Display {
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
            virtual void tick(sf::RenderWindow &window) = 0;
            virtual void event(sf::RenderWindow &window, const sf::Event &event) = 0;
            virtual void start(sf::RenderWindow &window) = 0;
            virtual void end() = 0;

        protected:
        private:
    };
}

#endif /*IDISPLAYMODULE_HPP_*/
