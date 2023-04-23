/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYFACTORY_HPP_
    #define ENTITYFACTORY_HPP_
    #include "TFactory.hpp"
    #include "EntityHandler.hpp"
    #include "IEntity.hpp"

class EntityFactory : public TFactory<EntityHandler, Scenes::IEntity> {
    public:
		~EntityFactory() = default;
        void addEntity(const std::string &name, std::unique_ptr<EntityHandler> handler);
        Scenes::IEntity getEntity(const std::string &name, IConfig config);
        static EntityFactory &getEntityFactory();

	protected:
        EntityFactory();
	private:
};

#endif /*ENTITYFACTORY_HPP_*/
