/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IEntityFactory.hpp
*/

#ifndef IMATERIALFACTORY_HPP_
    #define IMATERIALFACTORY_HPP_

    #include <string>
    #include <memory>
    #include "ILogger.hpp"
    #include "IMaterial.hpp"
    #include "ISetting.hpp"

namespace RayTracer::Factories {
    class IMaterialFactory {
        public:
            virtual ~IMaterialFactory() = default;
            /**
             * @brief Get an entity
             *
             * @param name the name
             * @param setting the setting (to create the entity)
             *
             * @return the entity
             */
            virtual Entities::IMaterial &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) = 0;
    };
}

extern "C" {
    extern RayTracer::Factories::IMaterialFactory *getMaterialFactoryInstance(void);
}

#endif
