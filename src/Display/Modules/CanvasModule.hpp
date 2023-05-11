/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CanvasModule.hpp
*/

#ifndef CANVASMODULE_HPP_
    #define CANVASMODULE_HPP_

    #include "ICamera.hpp"
#include "IDisplayModule.hpp"
#include "ITransform.hpp"
    #include "Scene.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"
#include <SFML/Graphics/Image.hpp>
#include <functional>

namespace RayTracer::Display {
    class CanvasModule : public IDisplayModule {
        public:
            CanvasModule(Scenes::Scene &scene, std::size_t &position);
            void tick(sf::RenderWindow &window) final;
            void event(sf::RenderWindow &window, const sf::Event &event) final;
            void start(sf::RenderWindow &window) final;
            void end() final;
            std::string getName() const final;

        protected:
        private:
            void resizeWindow(sf::RenderWindow &window);
            void execIfReady(std::function<void(Entities::ICamera &, Entities::Transform::ITransform &)> func);

            void goToNextCamera(sf::RenderWindow &window, const sf::Event &event);
            void goToPreviousCamera(sf::RenderWindow &window, const sf::Event &event);
            void addFocalLength(sf::RenderWindow &window, const sf::Event &event);
            void removeFocalLength(sf::RenderWindow &window, const sf::Event &event);
            void goLeft(sf::RenderWindow &window, const sf::Event &event);
            void goRight(sf::RenderWindow &window, const sf::Event &event);
            void goForward(sf::RenderWindow &window, const sf::Event &event);
            void goBackward(sf::RenderWindow &window, const sf::Event &event);
            void goUp(sf::RenderWindow &window, const sf::Event &event);
            void goDown(sf::RenderWindow &window, const sf::Event &event);

            Scenes::Scene &_scene;
            std::size_t &_position;
    };
}

#endif /*CANVASMODULE_HPP_*/
