/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display.hpp
*/
#ifndef DISPLAY_HPP_
	#define DISPLAY_HPP_

    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "Scene.hpp"
    #include "IDisplayModule.hpp"

namespace RayTracer::Display {
    class Display {
        public:
            Display(Scenes::Scene &scene);
            ~Display() = default;
            void start();

        protected:
        private:
            std::vector<std::unique_ptr<IDisplayModule>> _modules;
            Scenes::Scene &_scene;
            sf::Font _font;
            size_t position = 0;
    };

}

#endif /*DISPLAY_HPP_*/