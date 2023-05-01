/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#include <stdexcept>
#include <string>
#include <iostream>
#include "Main.hpp"
#include "Scene.hpp"
#include "SceneLoader.hpp"
#include "Parameters.hpp"

namespace RayTracer {
    Main::Main(int argc, char **argv):
        _parameters(Parameters::getInstance()), _exitCode(0)
    {
        _parameters.parseCmdArgs(argc, argv);
        try {
            _sceneConfFilePath = _parameters.getString("scene-path");
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            _exitCode = 1;
        }
        return;
        try {
            _baseFilePath = _parameters.getString("output-path");
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            _exitCode = 1;
        }
        return;
    }

    void Main::run()
    {
        if (_exitCode != 0) {
            return;
        }
        Scenes::SceneLoader loader(_sceneConfFilePath);
        loader.subscribe("onChange", _scene);
        loader.update();
        while (!_scene.isReady()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            try {
                loader.update();
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        exportScene(_baseFilePath);
    }

    void Main::exportScene(const std::string &baseFilePath)
    {
        int i = 0;

        for (const auto &camera : _scene.getCameras()) {
            try {
                camera->getImage().convertToPPM(baseFilePath + std::to_string(i) + ".ppm");
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                _exitCode = 1;
            }
            i++;
        }
    }

    int Main::getExitCode() const
    {
        return _exitCode;
    }
}

int main(int argc, char **argv)
{
    int exitCode = 0;
    RayTracer::Main main(argc, argv);

    main.run();
    exitCode = main.getExitCode();
    return exitCode;
}
