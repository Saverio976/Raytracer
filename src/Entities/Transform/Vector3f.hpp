/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3f.hpp
*/
#ifndef VECTOR3F_HPP_
    #define VECTOR3F_HPP_

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
            Vector3f(float x, float y, float z);
            /**
             * @brief Addition two vectors
             *
             * @param other the other vector
             *
             * @return the new
             */
            Vector3f operator+(const Vector3f &other);
            /**
             * @brief Subtraction two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator-(const Vector3f &other);
            /**
             * @brief Multiplication two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator*(const Vector3f &other);
            /**
             * @brief Division two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector3f operator/(const Vector3f &other);
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
            float getX() const;
            /**
             * @brief Get y
             *
             * @return y
             */
            float getY() const;
            /**
             * @brief Get z
             *
             * @return z
             */
            float getZ() const;

        protected:
        private:
            float _x;
            float _y;
            float _z;
    };
}

#endif /*VECTOR3F_HPP_*/
