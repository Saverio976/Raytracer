/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CanvasModule.cpp
*/

#include <future>
#include "CanvasModule.hpp"

namespace RayTracer::Display {
    CanvasModule::CanvasModule(Scenes::Scene &scene, std::size_t &position):
    _scene(scene),
    _position(position) {
        while (!this->_scene.getCameras().size()) {
        }
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();

        this->_texture.create(size.getX(), size.getY());
    }

    void CanvasModule::tick(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();
        
        sf::Color *pixels = new sf::Color[size.getX() * size.getY()];
        for (int x = 0; x < size.getX(); x++) {
            for (int y =  0; y < size.getY(); y++) {
                try {
                    pixels[y * size.getX() + x] = camera.getImage().getPixelsList().at(y * size.getX() + x).toSfColor();
                } catch(const std::exception& e) {
                    pixels[y * size.getX() + x] = sf::Color(0, 0, 0);
                }
            }
        }
        this->_texture.update((sf::Uint8 *) pixels, size.getX(), size.getY(), 0, 0);
        delete [] pixels;
        this->_sprite.setTexture(this->_texture);
        window.draw(this->_sprite);
    }

    void CanvasModule::start(sf::RenderWindow &window) {

    }

    void CanvasModule::resizeWindow(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();

        window.setSize({size.getX(), size.getY()});
        window.setView(sf::View({0, 0, size.getX(), size.getY()}));
    }

    void CanvasModule::event(sf::RenderWindow &window, const sf::Event &event) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                this->_position = (this->_position + 1) % this->_scene.getCameras().size();
                this->resizeWindow(window);
            }
            if (event.key.code == sf::Keyboard::D) {
                this->_position = (this->_position - 1) % this->_scene.getCameras().size();
                this->resizeWindow(window);
            }
            if (event.key.code == sf::Keyboard::Left) {
                if (this->_scene.isReady()) {
                    Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();

                    camera.setFocal(camera.getFocal() + 10);
                    this->_scene.renders();
                }
            }
        }
    }

    void CanvasModule::end() {

    }
}