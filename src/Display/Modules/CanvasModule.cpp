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
    _position(position) { }

    void CanvasModule::tick(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();
        sf::Texture texture;
        sf::Sprite sprite;
        texture.create(size.getX(), size.getY());

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
        texture.update((sf::Uint8 *) pixels, size.getX(), size.getY(), 0, 0);
        delete [] pixels;
        sprite.setTexture(texture);
        window.draw(sprite);
    }

    void CanvasModule::start(sf::RenderWindow &window) {

    }

    void CanvasModule::resizeWindow(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();

        window.setSize({static_cast<unsigned int>(size.getX()), static_cast<unsigned int>(size.getY())});
        window.setView(sf::View({0, 0, static_cast<float>(size.getX()), static_cast<float>(size.getY())}));
    }

    void CanvasModule::event(sf::RenderWindow &window, const sf::Event &event) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector3f position = camera.getTransform().getPosition();

        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Q:
                    this->_position = (this->_position + 1) % this->_scene.getCameras().size();
                    this->resizeWindow(window);
                    break;
                case sf::Keyboard::D:
                    this->_position = (this->_position - 1) % this->_scene.getCameras().size();
                    this->resizeWindow(window);
                    break;
                case sf::Keyboard::Z:
                    if (this->_scene.isReady()) {
                        camera.setFocal(camera.getFocal() + 10);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::S:
                    if (this->_scene.isReady()) {
                        camera.setFocal(camera.getFocal() - 10);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::Left:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(-10, 0, 0);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::Right:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(10, 0, 0);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::Up:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(0, 10, 0);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::Down:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(0, -10, 0);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::R:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(0, 0, 10);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                case sf::Keyboard::F:
                    if (this->_scene.isReady()) {
                        position = position + Entities::Transform::Vector3f(0, 0, -10);
                        camera.getTransform().setPosition(position);
                        this->_scene.renders();
                    }
                    break;
                default:
                    break;

            }
        }
    }

    void CanvasModule::end() {

    }
}