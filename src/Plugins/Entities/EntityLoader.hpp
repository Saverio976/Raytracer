/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityLoader.hpp
*/

#ifndef ENTITYLOADER_HPP_
    #define ENTITYLOADER_HPP_

    #include <string>
    #include "TFactory.hpp"
    #include "IEntity.hpp"
    #include "EntityHandler.hpp"

namespace RayTracer::Plugins::Entities {
    class EntityLoader {
    public:
        EntityLoader(const std::string &directory);

        virtual void load(Factories::TFactory <EntityHandler, RayTracer::Entities::IEntity> &factory);

    protected:
    private:
        std::string _directory;
    };
}

#endif /*ENTITYLOADER_HPP_*/
