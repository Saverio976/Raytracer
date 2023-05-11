/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display.hpp
*/
#ifndef DISPLAY_HPP_
    #define DISPLAY_HPP_

    #include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
    #include <SFML/Graphics.hpp>
    #include "ILogger.hpp"
    #include "Scene.hpp"
    #include "SceneLoader.hpp"
    #include "IDisplayModule.hpp"

namespace RayTracer::Display {
    class Display {
        public:
            class StartFailed : public std::exception {
                public:
                    StartFailed(const std::string &msg) : _msg(msg) {}
                    virtual const char *what() const throw() { return _msg.c_str(); }
                private:
                    std::string _msg;

            };
            Display(ILogger &logger, Scenes::Scene &scene, Scenes::SceneLoader &loader);
            ~Display() = default;
            void start();

        protected:
        private:
            void removeModule(const std::vector<std::string> &modulesToRemove);
            void run(sf::RenderWindow &window);
            void end();
            std::vector<std::unique_ptr<IDisplayModule>> _modules;
            Scenes::Scene &_scene;
            Scenes::SceneLoader &_loader;
            sf::Font _font;
            size_t _position = 0;
            ILogger &_logger;
    };

}

#endif /*DISPLAY_HPP_*/
