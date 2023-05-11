/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display.cpp
*/

#include "Display.hpp"
#include "CanvasModule.hpp"
#include "IDisplayModule.hpp"
#include "ILogger.hpp"

namespace RayTracer::Display {
    Display::Display(ILogger &logger, Scenes::Scene &scene, Scenes::SceneLoader &loader) :
        _scene(scene),
        _loader(loader),
        _logger(logger)
    {
        if (!this->_font.loadFromFile("./Assets/arial.ttf")) {
            throw StartFailed("error init font");
        }
        this->_modules.push_back(std::make_unique<CanvasModule>(scene, this->_position));
    }

    void Display::start() {
        Entities::Transform::Vector2i size = this->_scene.getCameras()[this->_position].get().getSize();
        sf::RenderWindow window(sf::VideoMode(size.getX(), size.getY()), "Militar Perform", sf::Style::Titlebar | sf::Style::Close);
        std::vector<std::string> namesToDelete;

        for (auto &module : this->_modules) {
            try {
                module->start(window);
            } catch (const IDisplayModule::StartFailed &e) {
                _logger.error("DisplaySFML: start failed for '" + module->getName() + "': " + std::string(e.what()));
            } catch (const std::exception &e) {
                _logger.fatal(module->getName() + ": start failed: " + std::string(e.what()));
                namesToDelete.push_back(module->getName());
            }
        }
        removeModule(namesToDelete);
        namesToDelete.clear();
        run(window);
    }

    void Display::removeModule(const std::vector<std::string> &modulesToRemove)
    {
        for (auto &module : modulesToRemove) {
            auto found = this->_modules.end();
            for (auto it = this->_modules.begin(); it != this->_modules.end(); it++) {
                if ((*it)->getName() == module) {
                    found = it;
                    break;
                }
            }
            if (found != this->_modules.end()) {
                this->_modules.erase(found);
            }
        }
    }

    void Display::run(sf::RenderWindow &window)
    {
        sf::Event event;
        sf::Clock time;
        const sf::Color background(0, 0, 0);
        std::vector<std::string> namesToDelete;

        while (window.isOpen()) {
            if (time.getElapsedTime().asSeconds() > 1) {
                this->_loader.update();
                time.restart();
            }
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    this->_scene.cancel();
                }
                for (auto &module : this->_modules) {
                    try {
                        module->event(window, event);
                    } catch (const IDisplayModule::EventFailed &e) {
                        _logger.error("DisplaySFML: event failed for '" + module->getName() + "': " + std::string(e.what()));
                    } catch (const std::exception &e) {
                        _logger.fatal(module->getName() + ": event failed: " + std::string(e.what()));
                        namesToDelete.push_back(module->getName());
                    }
                }
                removeModule(namesToDelete);
                namesToDelete.clear();
            }
            window.clear(background);
            for (auto &module : this->_modules) {
                try {
                    module->tick(window);
                } catch (const IDisplayModule::TickFailed &e) {
                    _logger.error("DisplaySFML: tick failed for '" + module->getName() + "': " + std::string(e.what()));
                } catch (const std::exception &e) {
                    _logger.fatal(module->getName() + ": tick failed: " + std::string(e.what()));
                    namesToDelete.push_back(module->getName());
                }
            }
            removeModule(namesToDelete);
            namesToDelete.clear();
            window.display();
        }

    }

    void Display::end()
    {
        std::vector<std::string> namesToDelete;

        for (auto &module : this->_modules) {
            try {
                module->end();
            } catch (const IDisplayModule::EndFailed &e) {
                _logger.error("DisplaySFML: end failed for '" + module->getName() + "': " + std::string(e.what()));
            } catch (const std::exception &e) {
                _logger.fatal(module->getName() + ": end failed: " + std::string(e.what()));
                namesToDelete.push_back(module->getName());
            }
        }
        removeModule(namesToDelete);
        namesToDelete.clear();
        _logger.info("DisplaySFML: quiting...");
    }
}
