/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityHandler.hpp
*/

#ifndef ENTITYHANDLER_HPP_
    #define ENTITYHANDLER_HPP_

    #include <memory>
    #include <string>
    #include "IEntity.hpp"
    #include "IEntityCreator.hpp"
    #include "PluginHandler.hpp"

class IConfig; // TODO: create an iconfig please

class EntityHandler : PluginHandler<Scenes::IEntity, IEntityCreator> {
    public:
        enum class Type {
            Light,
            Camera,
            Primitive
        };
        EntityHandler(const std::string &filePath);
        Type getType() const;
        std::unique_ptr<Scenes::IEntity> getEntity(const IConfig &config);
    private:
        Type _type;
};

#endif
