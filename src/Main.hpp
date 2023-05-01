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
            /**
             * @brief Construct a new Main object from argc and argv
             *
             * @param argc (argc from main func)
             * @param argv (argv from main func)
             */
            Main(int argc, char **argv);
            ~Main() = default;

            /**
             * @brief Run the main (like the main func but in a method :eyes:)
             */
            void run();
            /**
             * @brief Get the exit code of the main
             *
             * @return the exit code
             */
            int getExitCode() const;

        private:
            /**
             * @brief Export the scene to ppm files
             *
             * @param baseFilePath
             */
            void exportScene(const std::string &baseFilePath);
            Parameters &_parameters;
            int _exitCode;
            std::string _baseFilePath;
            std::string _sceneConfFilePath;
            Scenes::Scene _scene;
    };
}

#endif
