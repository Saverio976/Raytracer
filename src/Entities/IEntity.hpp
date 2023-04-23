/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_
    #include "Transform/ITransform.hpp"

namespace Scenes {
    /**
     * @brief The IEntity class
     *
     * Object available in a scene
     */
    class IEntity {
        public:
            virtual ~IEntity() = default;
            /**
             * @brief Get the transform (position, rotation, scale)
             *
             * @return the transform
             */
            virtual ITransform &getTransform() = 0;

        protected:
        private:
    };
}

#endif /*ENTITY_HPP_*/
