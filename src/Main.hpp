/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#ifndef MAIN_HPP
    #define MAIN_HPP

    #include "Parameters.hpp"
#include "Scene.hpp"
#include <memory>
#include <string>

namespace RayTracer {
    class Main {
        public:
            Main(int argc, char **argv);
            ~Main() = default;

            void run();
            void exportScene(const std::string &baseFilePath);
            int getExitCode() const;

        private:
            Parameters &_parameters;
            int _exitCode;
            std::string _baseFilePath;
            std::string _sceneConfFilePath;
            Scenes::Scene _scene;
    };
}

#endif
