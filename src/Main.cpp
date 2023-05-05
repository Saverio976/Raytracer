/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#include <future>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "ISetting.hpp"
#include "Main.hpp"
#include "Scene.hpp"
#include "SceneLoader.hpp"
#include "Parameters.hpp"

namespace RayTracer {
    bool Main::parseCmdArgs(int argc, char **argv)
    {
        Parameters::getInstance().parseCmdArgs(argc, argv);
        try {
            _help = Parameters::getInstance().getString("help");
            if (_help == "true" || _help == "") {
                help();
                return false;
            } else {
                throw ArgumentError("bad argument:: --help");
            }
        } catch (const Parameters::KeyNotFoundError &e) { }
        try {
            _sceneConfFilePath = Parameters::getInstance().getString("scene-path");
        } catch (const Parameters::KeyNotFoundError &e) {
            throw ArgumentError("missing argument:: --scene-path <path>");
        }
        try {
            _baseFilePath = Parameters::getInstance().getString("output-path");
        } catch (const Parameters::KeyNotFoundError &e) {
            throw ArgumentError("missing argument:: --output-path <path>");
        }
        return true;
    }

    void Main::run()
    {
        Scenes::SceneLoader loader(_sceneConfFilePath);

        loader.subscribe("onChange", [&](const Scenes::ISetting &setting) {
            _scene(setting);
        });
        try {
            loader.update();
            this->_scene.renders();
        } catch (const std::exception &e) {
            std::string message = e.what();
            throw MainError("Loader/Render error:: " + message);
        }
        while (!_scene.isReady()) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            try {
                loader.update();
            } catch (const std::exception &e) {
                std::cerr << e.what() << ": Waiting 5 more seconds (unlimited times)" << std::endl;
            }
        }
    }

    void Main::exportScene(const std::string &baseFilePath)
    {
        int i = 0;
        std::vector<std::future<void>> futures;

        for (const auto &camera : _scene.getCameras()) {
            RayTracer::Entities::ICamera *cam = camera.get();
            futures.push_back(std::async(std::launch::async, [cam, baseFilePath, i]() {
                try {
                    cam->getImage().convertToPPM(baseFilePath + std::to_string(i) + ".ppm");
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
            i++;
        }
        while (futures.size() > 0) {
            futures.front().wait();
            futures.erase(futures.begin());
        }
    }

    void Main::help() const
    {
        std::cout << "USAGE: ./raytracer --scene-path scene-conf.yaax --output-path file" << std::endl;
        std::cout << "USAGE: ./raytracer --help" << std::endl;
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

    int Main::operator()(int argc, char **argv)
    {
        bool isProceed = true;
        try {
            isProceed = parseCmdArgs(argc, argv);
        } catch (const ArgumentError &e) {
            std::string message = e.what();
            this->help();
            throw MainError("Parse Command Argument: " + message);
        }
        if (!isProceed) {
            return 0;
        }
        run();
        exportScene(_baseFilePath);
        return 0;
    }

    // -----------------------------------------------------------------------
    // Main::MainError
    // -----------------------------------------------------------------------

    Main::MainError::MainError(const std::string &message):
        _message(message)
    {
    }

    const char *Main::MainError::what() const noexcept
    {
        return _message.c_str();
    }

    // -----------------------------------------------------------------------
    // Main::ArgumentError
    // -----------------------------------------------------------------------

    Main::ArgumentError::ArgumentError(const std::string &message):
        _message(message)
    {
    }

    const char *Main::ArgumentError::what() const noexcept
    {
        return _message.c_str();
    }
}

int main(int argc, char **argv)
{
    int exitCode = 0;
    RayTracer::Main main;

    try {
        exitCode = main(argc, argv);
    } catch (const RayTracer::Main::MainError &e) {
        std::cerr << e.what() << std::endl;
        exitCode = 84;
    }
    return exitCode;
}
