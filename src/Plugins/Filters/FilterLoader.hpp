/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterLoader.hpp
*/
#ifndef FILTERLOADER_HPP_
    #define FILTERLOADER_HPP_

    #include <string>
    #include "TFactory.hpp"
    #include "IFilter.hpp"
    #include "FilterHandler.hpp"
    #include "PluginLoader.hpp"

namespace RayTracer::Plugins::Filters {
    class FilterLoader : public PluginLoader<FilterHandler, RayTracer::Filters::IFilter> {
    public:
        FilterLoader(const std::string &directory);

        void load(Factories::TFactory <FilterHandler, RayTracer::Filters::IFilter> &factory) override;

        void load();

    protected:
    private:
        std::string _directory;
    };
}

#endif /*FILTERLOADER_HPP_*/
