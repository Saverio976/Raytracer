/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityFactory.cpp
*/

#include <memory>
#include "IMaterialFactory.hpp"
#include "MaterialFactory.hpp"
#include "MaterialHandler.hpp"
#include "IMaterial.hpp"
#include "ILogger.hpp"
#include "TFactory.hpp"

namespace RayTracer::Factories {
    template<> std::unique_ptr<TFactory<Plugins::Materials::MaterialHandler, Entities::IMaterial>> TFactory<Plugins::Materials::MaterialHandler, Entities::IMaterial>::_factory = nullptr;
    std::unique_ptr<MaterialFactory> MaterialFactory::_factory = nullptr;

    void MaterialFactory::add(const std::string &name, std::unique_ptr<Plugins::Materials::MaterialHandler> handler)
    {
        getFactory().add(name, std::move(handler));
    }

    Entities::IMaterial &MaterialFactory::get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger)
    {
        return getFactory().get(name, setting, logger);
    }

    void MaterialFactory::clearAll()
    {
        getFactory().clearAll();
    }

    TFactory<Plugins::Materials::MaterialHandler, Entities::IMaterial> &MaterialFactory::getFactory()
    {
        return TFactory<Plugins::Materials::MaterialHandler, Entities::IMaterial>::getFactory();
    }

    MaterialFactory &MaterialFactory::getInstance()
    {
        if (_factory == nullptr)
            _factory.reset(new MaterialFactory());
        return *_factory;
    }
}

extern "C" {
    RayTracer::Factories::IMaterialFactory *getMaterialFactoryInstance(void)
    {
        return &RayTracer::Factories::MaterialFactory::getInstance();
    }
}
