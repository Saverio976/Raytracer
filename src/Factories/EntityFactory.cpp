/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityFactory.cpp
*/

#include <memory>
#include "EntityFactory.hpp"
#include "EntityHandler.hpp"
#include "IEntity.hpp"
#include "ILogger.hpp"
#include "TFactory.hpp"

namespace RayTracer::Factories {
    template<> std::unique_ptr<TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>> TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>::_factory = nullptr;
    std::unique_ptr<EntityFactory> EntityFactory::_factory = nullptr;

    void EntityFactory::add(const std::string &name, std::unique_ptr<Plugins::Entities::EntityHandler> handler)
    {
        getFactory().add(name, std::move(handler));
    }

    Entities::IEntity &EntityFactory::get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger)
    {
        return getFactory().get(name, setting, logger);
    }

    void EntityFactory::clearAll()
    {
        getFactory().clearAll();
    }

    TFactory<Plugins::Entities::EntityHandler, Entities::IEntity> &EntityFactory::getFactory()
    {
        return TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>::getFactory();
    }

    EntityFactory &EntityFactory::getInstance()
    {
        if (_factory == nullptr)
            _factory.reset(new EntityFactory());
        return *_factory;
    }
}
