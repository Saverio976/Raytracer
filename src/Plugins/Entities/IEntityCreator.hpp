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
    #include "ILogger.hpp"
    #include "ISetting.hpp"

namespace RayTracer::Plugins::Entities {
    /**
     * @brief The IEntityCreator
     *
     * class that represent an entity creator
     */
    class IEntityCreator {
        public:
            virtual ~IEntityCreator() = default;
            /**
            * @brief Create an entity with a setting
            *
            * @param setting the setting
            *
            * @return the entity
            */
            virtual RayTracer::Entities::IEntity *create(const Scenes::ISetting &setting, ILogger &logger) = 0;

        protected:
        private:
    };
}

#endif /*IENTITYCREATOR_HPP_*/
