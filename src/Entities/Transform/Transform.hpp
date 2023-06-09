/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Transform.hpp
*/

#ifndef TRANSFORM_HPP_
    #define TRANSFORM_HPP_
    #include "ITransform.hpp"
    #include "ISetting.hpp"
    #include "Vector3f.hpp"

namespace RayTracer::Entities::Transform {
    /**
     * @brief The Transform class
     *
     * class that represent a transform (position, rotation, scale, ..) of
     * an `IEntity`
     */
    class Transform : public ITransform {
        public:
            explicit Transform(const Scenes::ISetting &setting);
            /**
             * @brief Set the position
             *
             * @param position the position
             */
            void setPosition(const Vector3f &position) final;
            /**
             * @brief Get the position
             *
             * @return the position
             */
            const Vector3f &getPosition() const final;
            /**
             * @brief Set the rotation
             *
             * @param rotation the rotation
             */
            void setRotation(const Vector3f &rotation) final;
            /**
             * @brief Get the rotation
             *
             * @return the rotation
             */
            const Vector3f &getRotation() const final;
            /**
             * @brief Set the scale
             *
             * @param scale the scale
             */
            void setScale(const Vector3f &scale) final;
            /**
             * @brief Get the scale
             *
             * @return the scale
             */
            const Vector3f &getScale() const final;
            /**
             * @brief Assign a transform
             *
             * @param other the other transform
             *
             * @return the same transform modified
             */
            ITransform &operator=(const ITransform &other) final;

            protected:
            private:
                Vector3f _position;
                Vector3f _rotation;
                Vector3f _scale;

    };
}

#endif /*TRANSFORM_HPP_*/
