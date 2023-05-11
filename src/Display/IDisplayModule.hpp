/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IDisplayModule.hpp
*/
#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

    #include <SFML/Graphics.hpp>
#include <string>

namespace RayTracer::Display {
    class IDisplayModule {
        public:
            /**
             * @brief If the function start failed, but it can continue without being completed
             *
             * Any other exception will let the program continue and remove this module from list
             */
            class StartFailed : public std::exception {
                public:
                    StartFailed(const std::string &error): _error(error) {}
                    const char *what() const throw() { return _error.c_str(); }
                private:
                    std::string _error;
            };
            /**
             * @brief If the function end failed, but it can continue without being completed
             *
             * Any other exception will let the program continue and remove this module from list
             */
            class EndFailed : public std::exception {
                public:
                    EndFailed(const std::string &error): _error(error) {}
                    const char *what() const throw() { return _error.c_str(); }
                private:
                    std::string _error;
            };
            /**
             * @brief If the function event failed, but it can continue without being completed
             *
             * Any other exception will let the program continue and remove this module from list
             */
            class EventFailed : public std::exception {
                public:
                    EventFailed(const std::string &error): _error(error) {}
                    const char *what() const throw() { return _error.c_str(); }
                private:
                    std::string _error;
            };
            /**
             * @brief If the function tick failed, but it can continue without being completed
             *
             * Any other exception will let the program continue and remove this module from list
             */
            class TickFailed : public std::exception {
                public:
                    TickFailed(const std::string &error): _error(error) {}
                    const char *what() const throw() { return _error.c_str(); }
                private:
                    std::string _error;
            };
            virtual ~IDisplayModule() = default;
            virtual void tick(sf::RenderWindow &window) = 0;
            virtual void event(sf::RenderWindow &window, const sf::Event &event) = 0;
            virtual void start(sf::RenderWindow &window) = 0;
            virtual void end() = 0;
            virtual std::string getName() const = 0;

        protected:
        private:
    };
}

#endif /*IDISPLAYMODULE_HPP_*/
