/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterFactory.cpp
*/

#include "FilterFactory.hpp"
#include "FilterHandler.hpp"
#include "IFilter.hpp"
#include "ILogger.hpp"

namespace RayTracer::Factories {
    template<> std::unique_ptr<TFactory<Plugins::Filters::FilterHandler, Filters::IFilter>> TFactory<Plugins::Filters::FilterHandler, Filters::IFilter>::_factory = nullptr;

    void FilterFactory::add(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler)
    {
        getFactory().add(name, std::move(handler));
    }

    Filters::IFilter &FilterFactory::get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger)
    {
        return getFactory().get(name, setting, logger);
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
