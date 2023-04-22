/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP_
	#define IPRIMITIVE_HPP_
    #include "IMaterial.hpp"
    #include "Box.hpp"

namespace Scenes {
    class IPrimitive {
        public:
            ~IPrimitive() = default;
            IMaterial &getMaterial();
            const Box &getCollisionBox() const;
            bool isCollided(const Vector3f &point) const;

        protected:
        private:
    };
}

#endif /*IPRIMITIVE_HPP_*/
