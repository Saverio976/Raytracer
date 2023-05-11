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
#include <csignal>
#include "ILogger.hpp"
#include "ISetting.hpp"
#include "Logger.hpp"
#include "Main.hpp"
#include "Scene.hpp"
#include "SceneLoader.hpp"
#include "Parameters.hpp"
#include "Display.hpp"
#include "SceneState.hpp"

namespace RayTracer {
    static const std::vector<std::string> mainHelpHeader = {
"                                        ,----,                                               ",
"                                      ,/   .`|                                               ",
",-.----.                            ,`   .'  :                                               ",
"\\    /  \\                         ;    ;     /                                               ",
";   :    \\                      .'___,/    ,' __  ,-.                                __  ,-. ",
"|   | .\\ :                      |    :     |,' ,'/ /|                              ,' ,'/ /| ",
".   : |: |   ,--.--.        .--,;    |.';  ;'  | |' | ,--.--.     ,---.     ,---.  '  | |' | ",
"|   |  \\ :  /       \\     /_ ./|`----'  |  ||  |   ,'/       \\   /     \\   /     \\ |  |   ,' ",
"|   : .  / .--.  .-. | , ' , ' :    '   :  ;'  :  / .--.  .-. | /    / '  /    /  |'  :  /   ",
";   | |  \\  \\__\\/: . ./___/ \\: |    |   |  '|  | '   \\__\\/: . ..    ' /  .    ' / ||  | '    ",
"|   | ;\\  \\ ,\" .--.; | .  \\  ' |    '   :  |;  : |   ,\" .--.; |'   ; :__ '   ;   /|;  : |    ",
":   ' | \\.'/  /  ,.  |  \\  ;   :    ;   |.' |  , ;  /  /  ,.  |'   | '.'|'   |  / ||  , ;    ",
":   : :-' ;  :   .'   \\  \\  \\  ;    '---'    ---'  ;  :   .'   \\   :    :|   :    | ---'     ",
"|   |.'   |  ,     .-./   :  \\  \\                  |  ,     .-./\\   \\  /  \\   \\  /           ",
"`---'      `--`---'        \\  ' ;                   `--`---'     `----'    `----'            ",
"                            `--`                                                             "
    };

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

    // -----------------------------------------------------------------------
    // Main
    // -----------------------------------------------------------------------

    Main::Main(ILogger &logger):
        _logger(logger),
        _scene(logger)
    {
    }

    bool Main::parseCmdArgs(int argc, char **argv)
    {
        Parameters::getInstance().parseCmdArgs(argc, argv);
        Parameters::getInstance().setIfNotExists("help", "false");
        if (Parameters::getInstance().getString("help") == "") {
            this->help();
            return false;
        }
        Parameters::getInstance().setIfNotExists("EntitiesSO", "./plugins/Entities");
        Parameters::getInstance().setIfNotExists("FiltersSO", "./plugins/Filters");
        Parameters::getInstance().setIfNotExists("MaterialsSO", "./plugins/Materials");
        Parameters::getInstance().setIfNotExists("log-level", 3);
        try {
            Parameters::getInstance().getString("gui");
            Parameters::getInstance().set("display-mode", "gui");
        } catch (const Parameters::KeyNotFoundError &e) {
            Parameters::getInstance().set("display-mode", "console");
        }
        Parameters::getInstance().setIfNotExists("display-mode", "console");
        Parameters::getInstance().setIfNotExists("font-path", "./Assets/arial.ttf");
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
            Scenes::SceneLoader::checkGoodFile(_sceneConfFilePath);
        } catch (const Scenes::SceneLoader::BadFileError &e) {
            throw ArgumentError("bad argument:: --scene-path <path>:: " + std::string(e.what()));
        }
        _logger.trace("Finishing Parsing Command Arguments");
        return true;
    }

    void Main::run()
    {
        Scenes::SceneLoader loader(_sceneConfFilePath, _logger);
        bool isGui = Parameters::getInstance().getString("display-mode") == "gui";
        bool isCtrlC = false;

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
        if (isGui) {
            Display::Display display(this->_logger, this->_scene, loader);
            display.start();
        } else {
            std::signal(SIGINT, catch_sigint);
            while (!_scene.isReady()) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                if (isCtrlC) {
                    continue;
                }
                try {
                    Parameters::getInstance().getInt("signal");
                    this->_scene.cancel();
                    isCtrlC = true;
                } catch (const Parameters::KeyNotFoundError &e) {}
                try {
                    loader.update();
                } catch (const std::exception &e) {
                    _logger.warn(std::string(e.what()) + ": Waiting 5 more seconds (unlimited times)");
                }
            }
        }
    }

    void Main::exportScene(const std::string &baseFilePath)
    {
        int i = 0;
        std::vector<std::future<void>> futures;

        if (_scene.getState().getState() == Scenes::SceneState::States::CANCELLED) {
            return;
        }
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
        for (const auto &line : mainHelpHeader) {
            std::cout << line << std::endl;
        }
        std::cout << "__USAGE__:" << std::endl;
        std::cout << "\t./raytracer --scene-path <scene-conf.yaax> --output-path <file> [--log-level <int>] [--gui] [--font-path <font file>]" << std::endl;
        std::cout << "\t./raytracer --help" << std::endl;
        std::cout << std::endl;
        std::cout << "__OPTIONS__:" << std::endl;
        std::cout << "\t--scene-path <scene-conf.yaax> path to scene config" << std::endl;
        std::cout << "\t--output-path <file>           path to output file (dont put .ppm or any extension, it is just a base file path)" << std::endl;
        std::cout << "\t--help                         to display the help message" << std::endl;
        std::cout << "\t--log-level <int>              log level can be {-1: no log, 0: fatal, 1: error, 2: warn, 3: info, 4: debug, 5: trace} [3 by default]" << std::endl;
        std::cout << "\t--gui                          to display the images in GUI mode" << std::endl;
        std::cout << "\t--font-path <font file>        path to font file [./Assets/arial.ttf by default]" << std::endl;
        std::cout << std::endl;
        std::cout << "__IN WINDOW__:" << std::endl;
        std::cout << "\tZ                              : go forward to exit" << std::endl;
        std::cout << "\tQ                              : go left" << std::endl;
        std::cout << "\tS                              : go backward to exit" << std::endl;
        std::cout << "\tD                              : go right" << std::endl;
        std::cout << "\tSpace                          : go up" << std::endl;
        std::cout << "\tLeft Shift                     : go down" << std::endl;
        std::cout << "\tLeft Arrow                     : go previous camera" << std::endl;
        std::cout << "\tRight Arrow                    : go next camera" << std::endl;
        std::cout << std::endl;
        std::cout << "__CREDITS__:" << std::endl;
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
        if (this->_scene.getState().getState() == Scenes::SceneState::States::CANCELLED) {
            throw MainError("Cancelled..");
        }
        exportScene(_baseFilePath);
        return 0;
    }
}

extern "C" {
    void catch_sigint(int sig)
    {
        RayTracer::Parameters::getInstance().set("signal", sig);
        std::signal(SIGINT, SIG_DFL);
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
