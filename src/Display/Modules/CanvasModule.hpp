/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CanvasModule.hpp
*/

#ifndef CANVASMODULE_HPP_
    #define CANVASMODULE_HPP_

    #include "IDisplayModule.hpp"
    #include "Scene.hpp"

namespace RayTracer::Display {
    class CanvasModule : public IDisplayModule {
        public:
            CanvasModule(Scenes::Scene &scene);
            void tick(sf::RenderWindow &window) final;
            void event(sf::RenderWindow &window, const sf::Event &event) final;
            void start(sf::RenderWindow &window) final;
            void end() final;

        protected:
        private:
            Scenes::Scene &_scene;
    };
}

#endif /*CANVASMODULE_HPP_*/
