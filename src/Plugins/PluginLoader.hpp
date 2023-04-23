/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PluginLoader.hpp
*/
#ifndef PLUGINLOADER_HPP_
    #define PLUGINLOADER_HPP_
    #include <string>
    #include "TFactory.hpp"

namespace RayTracer::Plugins {
    template<typename Handler, typename Interface>
    class PluginLoader {
    public:
        PluginLoader(const std::string &directory);

        virtual void load(Factories::TFactory <Handler, Interface> &factory);

    protected:
        std::string _directory;
    private:
    };
}

#endif /*PLUGINLOADER_HPP_*/