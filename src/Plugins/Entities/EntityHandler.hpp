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
    #include "IConfig.hpp"

namespace RayTracer::Plugins::Entities {
    /**
     * @brief The EntityHandler
     *
     * class that represent an entity handler (take a .so)
     */
    class EntityHandler {
        public:
            /**
             * @brief EntityHandler constructor
             *
             * @param filePath the file path
             */
            EntityHandler(const std::string &filePath);
            /**
             * @brief Get an entity (and create it with config)
             *
             * @param config the config
             *
             * @return the entity
             */
            std::unique_ptr<RayTracer::Entities::IEntity> get(const RayTracer::Scenes::IConfig &config) const;
        private:
            PluginHandler<RayTracer::Entities::IEntity, IEntityCreator> _handler;
    };
}

#endif
