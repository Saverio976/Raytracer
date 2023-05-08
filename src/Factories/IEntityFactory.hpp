/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IEntityFactory.hpp
*/

#ifndef IENTITYFACTORY_HPP_
    #define IENTITYFACTORY_HPP_

    #include <string>
    #include <memory>
    #include "ILogger.hpp"
    #include "IEntity.hpp"
    #include "ISetting.hpp"

namespace RayTracer::Factories {
    class IEntityFactory {
        public:
            virtual ~IEntityFactory() = default;
            /**
             * @brief Get an entity
             *
             * @param name the name
             * @param setting the setting (to create the entity)
             *
             * @return the entity
             */
            virtual Entities::IEntity &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) = 0;
    };
}

extern "C" {
    extern RayTracer::Factories::IEntityFactory *getEntityFactoryInstance(void);
}

#endif
