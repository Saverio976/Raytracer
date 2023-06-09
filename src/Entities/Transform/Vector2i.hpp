/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector2i.hpp
*/

#ifndef VECTOR2I_HPP_
    #define VECTOR2I_HPP_

    #include <ostream>
    #include "IConfig.hpp"

namespace RayTracer::Entities::Transform {
    /**
     * @brief The Vector2i class
     *
     * point in 2D space
     */
    class Vector2i {
        public:
            ~Vector2i() = default;
            /**
             * @brief Construct a new Vector2i (x = 0, y = 0)
             */
            Vector2i();
            /**
             * @brief Construct a new Vector2i
             *
             * @param vector the vector
             */
            Vector2i(const Scenes::ISetting &config);
            /**
             * @brief Construct a new Vector2i
             *
             * @param vector the vector
             */
            Vector2i(const Vector2i &vector);
            /**
             * @brief Construct a new Vector2i
             *
             * @param width the width
             * @param height the height
             */
            Vector2i(int width, int height);
            /**
             * @brief Addition two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector2i operator+(const Vector2i &other) const;
            /**
             * @brief Subtraction two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector2i operator-(const Vector2i &other) const;
            /**
             * @brief Multiplication two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector2i operator*(const Vector2i &other) const;
            /**
             * @brief Division two vectors
             *
             * @param other the other vector
             *
             * @return the new vector
             */
            Vector2i operator/(const Vector2i &other) const;
            /**
             * @brief Assign a vector
             *
             * @param other the other vector
             *
             * @return the same vector modified
             */
            Vector2i &operator=(const Vector2i &other);
            /**
             * @brief Get x
             *
             * @return x
             */
            int getX() const;
            /**
             * @brief Get y
             *
             * @return y
             */
            int getY() const;

        protected:
        private:
            int _x;
            int _y;
    };
}

std::ostream& operator<<(std::ostream& os, const RayTracer::Entities::Transform::Vector2i& vector);

#endif /*VECTOR2I_HPP_*/
