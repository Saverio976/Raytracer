/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ITransform.hpp
*/

#ifndef ITRANSFORM_HPP_
    #define ITRANSFORM_HPP_
    #include "Vector3f.hpp"

namespace Scenes {
	/**
	 * @brief The ITransform class
	 *
	 * class that represent a transform (position, rotation, scale, ..) of
	 * an `IEntity`
	 */
    class ITransform {
        public:
            ~ITransform() = default;
            /**
             * @brief Set the position
             *
             * @param position the position
             */
            void setPosition(const Vector3f &position);
            /**
             * @brief Get the position
             *
             * @return the position
             */
            const Vector3f &getPosition() const;
            /**
             * @brief Set the rotation
             *
             * @param rotation the rotation
             */
            void setRotation(const Vector3f &rotation);
            /**
             * @brief Get the rotation
             *
             * @return the rotation
             */
            const Vector3f &getRotation() const;
            /**
             * @brief Set the scale
             *
             * @param scale the scale
             */
            void setScale(const Vector3f &scale);
            /**
             * @brief Get the scale
             *
             * @return the scale
             */
            const Vector3f &getScale() const;

        protected:
        private:
    };
}

#endif /*ITRANSFORM_HPP_*/
