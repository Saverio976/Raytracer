/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Box.hpp
*/
#ifndef BOX_HPP_
    #define BOX_HPP_
    #include "Vector3f.hpp"

namespace Scenes {
    /**
     * @brief The Box class
     *
     * class that represent a box
     */
    class Box {
        public:
            /**
             * @brief Construct a new Box object
             *
             * @param position the position
             * @param width the width
             * @param length the length
             * @param height the height
             */
            Box(const Vector3f &position, float width, float length, float height);
            ~Box();
            /**
             * @brief Check if a point is inside
             *
             * @param point the point
             *
             * @return true if the point is inside
             */
            bool isInside(const Vector3f &point) const;

        protected:
        private:
            Vector3f position;
            float width;
            float length;
            float height;
    };
}

#endif /*BOX_HPP_*/
