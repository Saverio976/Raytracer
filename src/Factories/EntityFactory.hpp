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
    class EntityFactory {
        public:
            ~EntityFactory();
            /**
             * @brief Add an entity
             *
             * @param name the name
             * @param handler the handler
             */
            static void add(const std::string &name, std::unique_ptr<Plugins::Entities::EntityHandler> handler);
            /**
             * @brief Get an entity
             *
             * @param name the name
             * @param config the config (to create the entity)
             *
             * @return the entity
             */
            static std::unique_ptr<Entities::IEntity> get(const std::string &name, const IConfig &config);
            /**
             * @brief Clear all handlers
             */
            static void clearAll();

        protected:
            static TFactory<Plugins::Entities::EntityHandler, Entities::IEntity> &getFactory();
        private:
    };
}

#endif /*ENTITYFACTORY_HPP_*/
