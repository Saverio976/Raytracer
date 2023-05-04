/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#include <stdexcept>
#include <string>
#include <iostream>
#include "ISetting.hpp"
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
            _help = _parameters.getString("help");
            if (_help == "true") {
                help();
                return;
            }
        } catch (const std::exception &e) { }
        try {
            _sceneConfFilePath = _parameters.getString("scene-path");
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            _exitCode = 84;
        }
        return;
        try {
            _baseFilePath = _parameters.getString("output-path");
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            _exitCode = 84;
        }
        return;
    }

    void Main::run()
    {
        if (_exitCode != 0 || _help == "true") {
            return;
        }
        Scenes::SceneLoader loader(_sceneConfFilePath);
        loader.subscribe("onChange", [&](const Scenes::ISetting &setting) {
            _scene(setting);
        });
        try {
            loader.update();
            this->_scene.renders();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            _exitCode = 84;
            return;
        }
        while (!_scene.isReady()) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            try {
                loader.update();
            } catch (const std::exception &e) {
                std::cerr << e.what() << ": Waiting 5 more seconds (unlimited times)" << std::endl;
            }
        }
        exportScene(_baseFilePath);
    }

    void Main::exportScene(const std::string &baseFilePath)
    {
        int i = 0;
        if (_exitCode != 0) {
            return;
        }
        for (const auto &camera : _scene.getCameras()) {
            try {
                camera->getImage().convertToPPM(baseFilePath + std::to_string(i) + ".ppm");
                _exitCode = 0;
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                _exitCode = 84;
            }
            i++;
        }
    }

    int Main::getExitCode() const
    {
        return _exitCode;
    }

    void Main::help() const
    {
        std::cout << "USAGE: ./raytracer --scene-path scene-conf.yaax --output-path file [--help true]" << std::endl;
        std::cout << std::endl;
        std::cout << "OPTIONS:" << std::endl;
        std::cout << "\t--scene-path scene-conf.yaax\tpath to scene config" << std::endl;
        std::cout << "\t--output-path file\tpath to output file (dont put .ppm or any extension, it is just a base file path)" << std::endl;
        std::cout << "\t--help true\tto display the help message" << std::endl;
        std::cout << std::endl;
        std::cout << "CREDITS:" << std::endl;
        std::cout << "\tAuthors: Y A A X" << std::endl;
        std::cout << "\tRepository: https://github.com/Saverio976/Raytracer" << std::endl;
    }
}

int main(int argc, char **argv)
{
    int exitCode = 0;
    RayTracer::Main main(argc, argv);

    if (main.getExitCode() != 0) {
        main.help();
        exitCode = main.getExitCode();
        return exitCode;
    }
    main.run();
    exitCode = main.getExitCode();
    return exitCode;
}
