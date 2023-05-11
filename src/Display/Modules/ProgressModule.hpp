/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ProgressModule.hpp
*/

#ifndef PROGRESSMODULE_HPP_
    #define PROGRESSMODULE_HPP_

    #include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Clock.hpp>
    #include <functional>
    #include "ICamera.hpp"
    #include "IDisplayModule.hpp"
    #include "ILogger.hpp"
    #include "ITransform.hpp"
    #include "Scene.hpp"
    #include "Transform.hpp"
    #include "Vector3f.hpp"

namespace RayTracer::Display {
    class ProgressModule : public IDisplayModule {
        public:
            ProgressModule(ILogger &logger);
            void tick(sf::RenderWindow &window) final;
            void event(sf::RenderWindow &window, const sf::Event &event) final;
            void start(sf::RenderWindow &window) final;
            void end() final;
            std::string getName() const final;

        protected:
        private:
            void info(const std::string &message);
            sf::RenderWindow _window;
            ILogger &_logger;
            std::string _message;
            sf::Font _font;
            sf::Clock _clock;
    };
}

#endif /*CANVASMODULE_HPP_*/
