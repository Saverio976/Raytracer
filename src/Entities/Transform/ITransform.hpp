/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ITransform.hpp
*/

#ifndef ITRANSFORM_HPP_
    #define ITRANSFORM_HPP_
    #include "Vector3f.hpp"

namespace RayTracer::Entities::Transform {
    /**
     * @brief The ITransform class
     *
     * class that represent a transform (position, rotation, scale, ..) of
     * an `IEntity`
     */
    class ITransform {
        public:
            virtual ~ITransform() = default;
            /**
             * @brief Set the position
             *
             * @param position the position
             */
            virtual void setPosition(const Vector3f &position) = 0;
            /**
             * @brief Get the position
             *
             * @return the position
             */
            virtual const Vector3f &getPosition() const = 0;
            /**
             * @brief Set the rotation
             *
             * @param rotation the rotation
             */
            virtual void setRotation(const Vector3f &rotation) = 0;
            /**
             * @brief Get the rotation
             *
             * @return the rotation
             */
            virtual const Vector3f &getRotation() const = 0;
            /**
             * @brief Set the scale
             *
             * @param scale the scale
             */
            virtual void setScale(const Vector3f &scale) = 0;
            /**
             * @brief Get the scale
             *
             * @return the scale
             */
            virtual const Vector3f &getScale() const = 0;
            /**
             * @brief Assign a transform
             *
             * @param other the other transform
             *
             * @return the same transform modified
             */
            virtual ITransform &operator=(const ITransform &other) = 0;

        protected:
        private:
    };
}

#endif /*ITRANSFORM_HPP_*/
