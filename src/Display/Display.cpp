/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display.cpp
*/

#include "Display.hpp"
#include "CanvasModule.hpp"

namespace RayTracer::Display {
    Display::Display(Scenes::Scene &scene) : _scene(scene) {
        if (!this->_font.loadFromFile("./Assets/arial.ttf"))
            throw std::runtime_error("error init font"); // TODO: Faire avec une erreur custom
        this->_modules.push_back(std::make_unique<CanvasModule>(scene));
    }

    void Display::start() {
        Entities::Transform::Vector2i size = this->_scene.getCameras()[this->position].get().getSize();
        sf::RenderWindow window(sf::VideoMode(size.getX(), size.getY()), "Militar Perform", sf::Style::Titlebar | sf::Style::Close);
        const sf::Color background(255, 255, 255);
        sf::Event event;

        for (auto &module : this->_modules) {
            try {
                module->start(window);
            } catch (std::exception &e) { // TODO: Faire avec une erreur custom
                throw std::runtime_error("error on start: [mettre l'erreur reçu]"); // TODO: Faire avec une erreur custom
            }
        }
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                for (auto &module : this->_modules) {
                    try {
                            module->event(window, event);
                    } catch (std::exception &e) {
                        throw std::runtime_error("error on start: [mettre l'erreur reçu]"); // TODO: Faire avec une erreur custom
                    }
                }
            }
            window.clear(background);
            for (auto &module : this->_modules) {
                try {
                    module->tick(window);
                } catch (std::exception &e) {
                    throw std::runtime_error("error on start: [mettre l'erreur reçu]"); // TODO: Faire avec une erreur custom
                }
            }
            window.display();
        }
        for (auto &module : this->_modules) {
            try {
                module->end();
            } catch (std::exception &e) { // TODO: Faire avec une erreur custom
                throw std::runtime_error("error on start: [mettre l'erreur reçu]"); // TODO: Faire avec une erreur custom
            }
        }
    }
}