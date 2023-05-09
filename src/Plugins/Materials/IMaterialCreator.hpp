/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFilterCreator.hpp
*/

#ifndef IMATERIALCREATOR_HPP_
    #define IMATERIALCREATOR_HPP_

    #include <memory>
    #include "IMaterial.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"

namespace RayTracer::Plugins::Materials {
    /**
     * @brief The IMaterialCreator class
     *
     * class that represent a material creator
     */
    class IMaterialCreator {
        public:
            virtual ~IMaterialCreator() = default;
            /**
             * @brief Create a material with a setting
             *
             * @param config the setting
             *
             * @return the material
             */
            virtual RayTracer::Entities::IMaterial *create(const Scenes::ISetting &setting, ILogger &logger) = 0;

        protected:
        private:
    };
}

#endif
