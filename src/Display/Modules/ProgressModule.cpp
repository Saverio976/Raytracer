/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ProgressModule.cpp
*/

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <stdexcept>
#include "ProgressModule.hpp"
#include "Parameters.hpp"

namespace RayTracer::Display {
    ProgressModule::ProgressModule(ILogger &logger):
        _logger(logger)
    {
    }

    void ProgressModule::tick(sf::RenderWindow &window)
    {
        sf::Text message;
        message.setFont(_font);
        message.setString(_message);
        message.setFillColor(sf::Color::White);
        message.setCharacterSize(window.getSize().x * 0.03);
        message.setPosition(5, 5);

        if (_clock.getElapsedTime().asSeconds() >= 5) {
            return;
        }
        window.draw(message);
    }

    void ProgressModule::event(sf::RenderWindow &window, const sf::Event &event)
    {
    }

    void ProgressModule::start(sf::RenderWindow &window)
    {
        _logger.subscribeCallback(3, getName(), std::bind(&ProgressModule::info, this, std::placeholders::_1));
        _clock.restart();
        if (!_font.loadFromFile(Parameters::getInstance().getString("font-path"))) {
            throw std::runtime_error("error init font");
        }
    }

    void ProgressModule::end()
    {
        _logger.unsubscribeCallback(3, getName());
    }

    std::string ProgressModule::getName() const
    {
        return "Progress";
    }

    void ProgressModule::info(const std::string &message)
    {
        _message = message;
        _clock.restart();
    }
}
