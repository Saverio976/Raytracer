/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3f.hpp
*/
#ifndef VECTOR3F_HPP_
#define VECTOR3F_HPP_

#include "ISetting.hpp"
namespace RayTracer::Entities::Transform {
    /**
     * @brief The Vector3f class
     *
     * point in 3D space
     */
    class Vector3f {
        public:
            ~Vector3f() = default;
            /**
             * @brief Construct a new Vector3f with x=0, y=0, z=0
             */
            Vector3f();
            /**
             * @brief Construct a new Vector3f
             *
             * @param vector3f the vector
             */
            Vector3f(const Vector3f &vector3f);
            /**
             * @brief Construct a new Vector3f
             *
             * @param x x position
             * @param y y position
             * @param z z position
             */
            Vector3f(double x, double y, double z);
            /**
             * @brief Construct a new Vector3f from a setting
             *
             * needed: x, y, z
             *
             * @param setting the setting
             */
            Vector3f(const Scenes::ISetting &setting);
            /**
             * @brief Addition two vectors
             *
             * @param other the other vector
             *
             * @return the new
             */
            Vector3f operator+(const Vector3f &other) const;
            /**
             * @brief Subtraction two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator-(const Vector3f &other) const;
            /**
             * @brief Multiplication two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator*(const Vector3f &other) const;
            /**
             * @brief Division two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator/(const Vector3f &other) const;
            /**
             * @brief Assign a vector
             *
             * @param other the other vector
             *
             * @return the same vector modified
             */
            Vector3f &operator=(const Vector3f &other);
            /**
             * @brief Get x
             *
             * @return x
             */
            double getX() const;
            /**
             * @brief Get y
             *
             * @return y
             */
            double getY() const;
            /**
             * @brief Get z
             *
             * @return z
             */
            double getZ() const;
            /**
             * @brief Get the norm
             *
             * @return sqrt(x^2 + y^2 + z^2)
             */
            double getNorm() const;
            /**
             * @brief Get normalized vector
             *
             * @return vector / getNorm()
             */
            Vector3f getNormalized() const;
            /**
             * @brief Get dot product
             *
             * @param other the other
             *
             * @return x^other.x + y^other.y + z^other.z
             */
            double dot(const Vector3f &other) const;
            /* @brief Get distance between this point and other point
             *
             * @param other the other point
             *
             * @return The distance value
             */
            double getDistance(const Vector3f &other) const;
            /* @brief Convert the vector to degrees from radians
             *
             * @return a new vector with the conversion
             */
            Vector3f toDegrees() const;
            /* @brief Convert the vector to radians from degrees
             *
             * @return a new vector with the conversion
             */
            Vector3f toRadians() const;
            /* @brief Rotate the vector (base, direction)
             *
             * @param direction the vector of the direction
             * @param rotation the rotation
             *
             * @return a new vector direction
             */
            Vector3f rotateVector(const Vector3f &direction, const Vector3f &rotation) const;

        protected:
        private:
            double _x;
            double _y;
            double _z;
    };
}

#endif /*VECTOR3F_HPP_*/
