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
    #include "SceneLoader.hpp"
    #include "IDisplayModule.hpp"

namespace RayTracer::Display {
    class Display {
        public:
            Display(Scenes::Scene &scene, Scenes::SceneLoader &loader);
            ~Display() = default;
            void start();

        protected:
        private:
            std::vector<std::unique_ptr<IDisplayModule>> _modules;
            Scenes::Scene &_scene;
            Scenes::SceneLoader &_loader;
            sf::Font _font;
            size_t _position = 0;
    };

}

#endif /*DISPLAY_HPP_*/