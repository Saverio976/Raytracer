/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterFactory.cpp
*/

#include "FilterFactory.hpp"
#include "FilterHandler.hpp"
#include "IFilter.hpp"

namespace RayTracer::Factories {
    template<> std::unique_ptr<TFactory<Plugins::Filters::FilterHandler, Filters::IFilter>> TFactory<Plugins::Filters::FilterHandler, Filters::IFilter>::_factory = nullptr;

    void FilterFactory::addFilter(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler)
    {
        getFactory().add(name, std::move(handler));
    }

    std::unique_ptr<Filters::IFilter> FilterFactory::getFilter(const std::string &name, const IConfig &config)
    {
        return getFactory().get(name, config);
    }

    void FilterFactory::clearAll()
    {
        getFactory().clearAll();
    }

    TFactory<Plugins::Filters::FilterHandler, Filters::IFilter> &FilterFactory::getFactory()
    {
        return TFactory<Plugins::Filters::FilterHandler, Filters::IFilter>::getFactory();
    }
}
