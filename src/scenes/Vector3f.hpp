/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3f.hpp
*/
#ifndef VECTOR3F_HPP_
	#define VECTOR3F_HPP_

namespace Scenes {
    class Vector3f {
        public:
            Vector3f(const Vector3f &vector3f);
            Vector3f(float x, float y, float z);
            ~Vector3f();
            Vector3f operator+(const Vector3f &other);
            Vector3f operator-(const Vector3f &other);
            Vector3f operator*(const Vector3f &other);
            Vector3f operator/(const Vector3f &other);
            Vector3f operator=(const Vector3f &other);

        protected:
        private:
            float x;
            float y;
            float z;
    };
}

#endif /*VECTOR3F_HPP_*/