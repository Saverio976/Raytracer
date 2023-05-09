/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityFactory.hpp
*/

#ifndef ENTITYFACTORY_HPP_
    #define ENTITYFACTORY_HPP_

    #include "IEntityFactory.hpp"
    #include "ILogger.hpp"
    #include "TFactory.hpp"
    #include "EntityHandler.hpp"
    #include "IEntity.hpp"

namespace RayTracer::Factories {
    /**
     * @brief The EntityFactory (singleton factory)
     */
    class EntityFactory : public IEntityFactory {
        public:
            EntityFactory(const EntityFactory &other) = delete;
            ~EntityFactory() = default;
            /**
             * @brief Add an entity
             *
             * @param name the name
             * @param handler the handler
             */
            void add(const std::string &name, std::unique_ptr<Plugins::Entities::EntityHandler> handler);
            /**
             * @brief Get an entity
             *
             * @param name the name
             * @param setting the setting (to create the entity)
             *
             * @return the entity
             */
            Entities::IEntity &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) final;
            /**
             * @brief Clear all handlers
             */
            void clearAll();
            /**
             * @brief Get the singleton
             *
             * @return the singleton
             */
            static EntityFactory &getInstance();

        protected:
            EntityFactory() = default;
            static TFactory<Plugins::Entities::EntityHandler, Entities::IEntity> &getFactory();
            static std::unique_ptr<EntityFactory> _factory;
        private:
    };
}

#endif /*ENTITYFACTORY_HPP_*/
