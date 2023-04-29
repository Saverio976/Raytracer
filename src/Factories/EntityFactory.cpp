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
#include "TFactory.hpp"

namespace RayTracer::Factories {
    template<> std::unique_ptr<TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>> TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>::_factory = nullptr;

    void EntityFactory::add(const std::string &name, std::unique_ptr<Plugins::Entities::EntityHandler> handler)
    {
        getFactory().add(name, std::move(handler));
    }

    std::unique_ptr<Entities::IEntity> EntityFactory::get(const std::string &name, const Scenes::ISetting &setting)
    {
        return getFactory().get(name, setting);
    }

    void EntityFactory::clearAll()
    {
        getFactory().clearAll();
    }

    TFactory<Plugins::Entities::EntityHandler, Entities::IEntity> &EntityFactory::getFactory()
    {
        return TFactory<Plugins::Entities::EntityHandler, Entities::IEntity>::getFactory();
    }
}
