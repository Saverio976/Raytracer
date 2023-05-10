/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#include <exception>
#include <future>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "ILogger.hpp"
#include "ISetting.hpp"
#include "Logger.hpp"
#include "Main.hpp"
#include "Scene.hpp"
#include "SceneLoader.hpp"
#include "Parameters.hpp"
#include "Display.hpp"

namespace RayTracer {
    Main::Main(ILogger &logger):
        _logger(logger),
        _scene(logger)
    {
    }

    bool Main::parseCmdArgs(int argc, char **argv)
    {
        std::string isHelp;
        int logLevel = 0;

        Parameters::getInstance().parseCmdArgs(argc, argv);
        try {
            isHelp = Parameters::getInstance().getString("help");
            if (isHelp == "true" || isHelp == "") {
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
        try {
            logLevel = Parameters::getInstance().getInt("log-level");
        } catch (const Parameters::KeyNotFoundError &e) {
            Parameters::getInstance().set("log-level", 3);
        }
        try {
            Scenes::SceneLoader::checkGoodFile(_sceneConfFilePath);
        } catch (const Scenes::SceneLoader::BadFileError &e) {
            std::string message = e.what();
            throw ArgumentError("bad argument:: --scene-path <path>:: " + message);
        }
        _logger.trace("Finishing Parsing Command Arguments");
        return true;
    }

    void Main::run()
    {
        Scenes::SceneLoader loader(_sceneConfFilePath, _logger);

        loader.subscribe("onChange", [&](const Scenes::ISetting &setting) {
            _scene(setting, "onChange");
        });
        loader.subscribe("onBeforeChange", [&](const Scenes::ISetting &setting) {
            _scene(setting, "onBeforeChange");
        });
        try {
            _logger.info("Loading Scene...");
            loader.update();
            _logger.info("Rendering Scene...");
        } catch (const std::exception &e) {
            std::string message = e.what();
            _logger.fatal("Loader/Render error:: " + message);
            throw MainError("Loader/Render error:: " + message);
        }
        Display::Display display(this->_scene);
        display.start();
        while (!_scene.isReady()) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            try {
                loader.update();
            } catch (const std::exception &e) {
                std::string message = e.what();
                _logger.warn(message + ": Waiting 5 more seconds (unlimited times)");
            }
        }
    }

    void Main::exportScene(const std::string &baseFilePath)
    {
        int i = 0;
        std::vector<std::future<void>> futures;

        for (const auto &camera : _scene.getCameras()) {
            futures.push_back(std::async(std::launch::async, [camera, baseFilePath, i, this]() {
                _logger.info("Exporting camera index " + std::to_string(i) + "...");
                try {
                    camera.get().getImage().convertToPPM(baseFilePath + std::to_string(i) + ".ppm");
                    _logger.trace("Exported camera index" + std::to_string(i));
                } catch (const std::exception &e) {
                    std::string message = e.what();
                    _logger.error("Export To PPM error (cam index: " + std::to_string(i) + "):: " + message);
                }
            }));
            i++;
        }
        while (futures.size() > 0) {
            _logger.trace("Waiting for camera to finish... (rest: " + std::to_string(futures.size()) + ")");
            futures.front().wait();
            futures.erase(futures.begin());
        }
    }

    void Main::help() const
    {
        std::cout << "USAGE: ./raytracer --scene-path <scene-conf.yaax> --output-path <file> [--log-level <int>]" << std::endl;
        std::cout << "USAGE: ./raytracer --help" << std::endl;
        std::cout << std::endl;
        std::cout << "OPTIONS:" << std::endl;
        std::cout << "\t--scene-path <scene-conf.yaax>\tpath to scene config" << std::endl;
        std::cout << "\t--output-path <file>\tpath to output file (dont put .ppm or any extension, it is just a base file path)" << std::endl;
        std::cout << "\t--help\tto display the help message" << std::endl;
        std::cout << "\t--log-level <int>\tlog level can be {-1: no log, 0: fatal, 1: error, 2: warn, 3: info, 4: debug, 5: trace} [3 by default]" << std::endl;
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
    RayTracer::Logger logger;
    RayTracer::Main main(logger);

    try {
        exitCode = main(argc, argv);
    } catch (const RayTracer::Main::MainError &e) {
        logger.fatal(e.what());
        exitCode = 84;
    }
    return exitCode;
}
