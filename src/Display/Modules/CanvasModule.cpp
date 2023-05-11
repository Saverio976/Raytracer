/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CanvasModule.cpp
*/

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <future>
#include <iostream>
#include "CanvasModule.hpp"
#include "Parameters.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

namespace RayTracer::Display {
    CanvasModule::CanvasModule(Scenes::Scene &scene, std::size_t &position):
    _scene(scene),
    _position(position) { }

    void CanvasModule::tick(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
        std::string message = "focal: " + std::to_string(camera.getFocal()) + "\n" +
                                "cluster: " + std::to_string(camera.getCluster()) + "\n" +
                                "position: (x:" +
                                    std::to_string(camera.getTransform().getPosition().getX()) +
                                    ", y:" +
                                    std::to_string(camera.getTransform().getPosition().getY()) +
                                    ", z:" +
                                    std::to_string(camera.getTransform().getPosition().getZ()) +
                                ")";
        sf::Text text;
        text.setFont(_font);
        text.setString(message);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(window.getSize().y * 0.03);
        text.setPosition(window.getSize().x - text.getGlobalBounds().width - 5, window.getSize().y - text.getGlobalBounds().height - 5);

        image.create(size.getX(), size.getY(), sf::Color(0, 0, 0));
        for (int x = 0; x < size.getX(); x++) {
            for (int y =  0; y < size.getY(); y++) {
                try {
                    image.setPixel(x, y, camera.getImage().getPixelsList().at(y * size.getX() + x).toSfColor());
                } catch(const std::exception& e) {
                    image.setPixel(x, y, sf::Color(0, 0, 0));
                }
            }
        }
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.draw(text);
    }

    void CanvasModule::start(sf::RenderWindow &window) {
        this->resizeWindow(window);
        if (!this->_font.loadFromFile(Parameters::getInstance().getString("font-path"))) {
            throw std::runtime_error("Can't load font");
        }
    }

    void CanvasModule::resizeWindow(sf::RenderWindow &window) {
        Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
        Entities::Transform::Vector2i size = camera.getSize();

        window.setSize({static_cast<unsigned int>(size.getX()), static_cast<unsigned int>(size.getY())});
        window.setView(sf::View({0, 0, static_cast<float>(size.getX()), static_cast<float>(size.getY())}));
    }

    void CanvasModule::event(sf::RenderWindow &window, const sf::Event &event) {
        std::map<sf::Keyboard::Key, std::function<void ()>> keyMap = {
            {sf::Keyboard::Right,           std::bind(&CanvasModule::goToNextCamera, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Left,            std::bind(&CanvasModule::goToPreviousCamera, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Down,            std::bind(&CanvasModule::addFocalLength, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Up,              std::bind(&CanvasModule::removeFocalLength, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Q,               std::bind(&CanvasModule::goLeft, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::D,               std::bind(&CanvasModule::goRight, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Space,           std::bind(&CanvasModule::goUp, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::LShift,          std::bind(&CanvasModule::goDown, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::S,               std::bind(&CanvasModule::goBackward, this, std::ref(window), std::ref(event))},
            {sf::Keyboard::Z,               std::bind(&CanvasModule::goForward, this, std::ref(window), std::ref(event))},
        };

        if (_clock.getElapsedTime() > sf::seconds(0.5) && this->_scene.getCameras()[this->_position].get().getCluster() != 1) {
            this->_scene.getCameras()[this->_position].get().setCluster(1);
            this->_scene.cancel();
            this->_scene.renders();
        }
        if (event.type == sf::Event::KeyPressed) {
            auto it = keyMap.find(event.key.code);
            if (it != keyMap.end()) {
                if (_clock.getElapsedTime() > sf::seconds(0.5)) {
                    this->_scene.getCameras()[this->_position].get().setCluster(5);
                }
                _clock.restart();
                it->second();
            }
        }
    }

    void CanvasModule::end() {

    }

    std::string CanvasModule::getName() const {
        return "Canvas";
    }

    void CanvasModule::execIfReady(std::function<void (Entities::ICamera &, Entities::Transform::ITransform &)> func)
    {
        if (this->_scene.isReady()) {
            Entities::ICamera &camera = this->_scene.getCameras()[this->_position].get();
            Entities::Transform::ITransform &transform = camera.getTransform();
            func(camera, transform);
            this->_scene.cancel();
            this->_scene.renders();
        }
    }

    void CanvasModule::goToNextCamera(sf::RenderWindow &window, const sf::Event &event)
    {
        this->_position = (this->_position + 1) % this->_scene.getCameras().size();
        this->resizeWindow(window);
        std::cout << "" << this->_position << std::endl;
    }

    void CanvasModule::goToPreviousCamera(sf::RenderWindow &window, const sf::Event &event)
    {
        this->_position = (this->_position - 1) % this->_scene.getCameras().size();
        this->resizeWindow(window);
        std::cout << "" << this->_position << std::endl;
    }

    void CanvasModule::addFocalLength(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            camera.setFocal(camera.getFocal() + 10);
        });
    }

    void CanvasModule::removeFocalLength(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            camera.setFocal(camera.getFocal() - 10);
        });
    }

    void CanvasModule::goLeft(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(-10, 0, 0)
            );
        });
    }

    void CanvasModule::goRight(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(10, 0, 0)
            );
        });
    }

    void CanvasModule::goUp(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(0, 0, 10)
            );
        });
    }

    void CanvasModule::goDown(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(0, 0, -10)
            );
        });
    }

    void CanvasModule::goBackward(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(0, -10, 0)
            );
        });
    }

    void CanvasModule::goForward(sf::RenderWindow &window, const sf::Event &event)
    {
        this->execIfReady([](Entities::ICamera &camera, Entities::Transform::ITransform &transform) {
            transform.setPosition(
                transform.getPosition() + Entities::Transform::Vector3f(0, 10, 0)
            );
        });
    }
}
