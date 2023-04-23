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
    #include "PluginLoader.hpp"
    #include "EntityHandler.hpp"

namespace RayTracer::Plugins::Entities {
    /**
     * @brief The EntityLoader
     *
     * class that represent an entity loader (take a directory and create EntityHandler)
     */
    class EntityLoader : protected PluginLoader<EntityHandler, RayTracer::Entities::IEntity> {
        public:
            /**
            * @brief EntityLoader constructor (doesn't load anything)
            *
            * @param directory the directory
            */
            EntityLoader(const std::string &directory);
            /**
            * @brief Load all the entities in the factory singleton
            */
            void loadEntities();

        protected:
        private:
            std::string _directory;
    };
}

#endif /*ENTITYLOADER_HPP_*/
