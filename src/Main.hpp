/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.cpp
*/

#ifndef MAIN_HPP
    #define MAIN_HPP

    #include <exception>
    #include <memory>
    #include <string>
    #include "ILogger.hpp"
    #include "Parameters.hpp"
    #include "Scene.hpp"

extern "C" {
    void catch_sigint(int sig);
}

namespace RayTracer {
    class Main {
        public:
            class MainError : public std::exception {
                public:
                    explicit MainError(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };
            /**
             * @brief Construct a new Main object from argc and argv
             *
             * @param argc (argc from main func)
             * @param argv (argv from main func)
             */
            Main(ILogger &logger);
            ~Main() = default;

            int operator()(int argc, char **argv);

        private:
            class ArgumentError : public std::exception {
                public:
                    explicit ArgumentError(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };
            /**
             * @brief Export the scene to ppm files
             *
             * @param baseFilePath
             */
            void exportScene(const std::string &baseFilePath);
            /**
             * @brief Run the main (like the main func but in a method :eyes:)
             */
            void run();
            /**
             * @brief Print the help
             */
            void help() const;
            /**
             * @brief Parse the command line argumens
             *
             * This method can throw an ArgumentError
             *
             * @param argc nb of arguments
             * @param argv arguments
             *
             * @return true if can proceed, false otherwise (but it is not an error)
             */
            bool parseCmdArgs(int argc, char **argv);

            std::string _baseFilePath;
            std::string _sceneConfFilePath;
            Scenes::Scene _scene;
            ILogger &_logger;
    };
}

#endif
