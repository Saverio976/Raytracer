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
    class ITransform {
        public:
            ~ITransform() = default;
            void setPosition(const Vector3f &position);
            const Vector3f &getPosition() const;
            void setRotation(const Vector3f &rotation);
            const Vector3f &getRotation() const;
            void setScale(const Vector3f &scale);
            const Vector3f &getScale() const;

        protected:
        private:
    };
}

#endif /*ITRANSFORM_HPP_*/
