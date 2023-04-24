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

namespace RayTracer::Factories {
    /**
     * @brief The EntityFactory (singleton factory)
     */
    class EntityFactory : public TFactory<Plugins::Entities::EntityHandler, Entities::IEntity> {
        public:
            ~EntityFactory() = default;
            EntityFactory(const EntityFactory &other) = delete;
            /**
             * @brief Add an entity
             *
             * @param name the name
             * @param handler the handler
             */
            void addEntity(const std::string &name, std::unique_ptr<Plugins::Entities::EntityHandler> handler);
            /**
             * @brief Get an entity
             *
             * @param name the name
             * @param config the config (to create the entity)
             *
             * @return the entity
             */
            std::unique_ptr<Entities::IEntity> getEntity(const std::string &name, IConfig config);
            /**
             * @brief Get the entity factory instance
             *
             * @return the entity factory instance
             */
            static EntityFactory &getEntityFactory();

        protected:
            EntityFactory();
        private:
    };
}

#endif /*ENTITYFACTORY_HPP_*/
