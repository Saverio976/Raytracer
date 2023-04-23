/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IEntityCreator.hpp
*/

#ifndef IENTITYCREATOR_HPP_
    #define IENTITYCREATOR_HPP_

    #include <memory>
    #include "IEntity.hpp"

class IConfig; // TODO: create an iconfig please

namespace RayTracer::Plugins::Entities {
    class IEntityCreator {
    public:
        virtual ~IEntityCreator() = default;

        virtual std::unique_ptr<RayTracer::Entities::IEntity> create(const IConfig &config) = 0;

    protected:
    private:
    };
}

#endif /*IENTITYCREATOR_HPP_*/
