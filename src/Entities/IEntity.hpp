/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_
    #include "Transform/ITransform.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The IEntity class
     *
     * Object available in a scene
     */
    class IEntity {
        public:
            enum class Type {
                Light,
                Camera,
                Primitive
            };
            virtual ~IEntity() = default;
            /**
             * @brief Get the transform (position, rotation, scale)
             *
             * @return the transform
             */
            virtual Transform::ITransform &getTransform() = 0;
            /**
             * @brief Get the transform (position, rotation, scale) (const)
             *
             * @return the transform
             */
            virtual const Transform::ITransform &getTransform() const = 0;
            /**
             * @brief Get the type (light, camera, primitive)
             *
             * @return the type
             */
            virtual Type getType() const = 0;

        protected:
        private:
    };
}

#endif /*ENTITY_HPP_*/
