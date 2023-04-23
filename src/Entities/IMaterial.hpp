/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_
    #include "../Images/Color.hpp"

namespace Scenes {
    /**
     * @brief The IMaterial class
     *
     * class that represent a material (color/texture)
     */
    class IMaterial {
        public:
            ~IMaterial() = default;
            /**
             * @brief Get the color
             *
             * @return the color
             */
            const Color &getColor() const;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            void setColor(const Color &color);

        protected:
        private:
    };
}

#endif /*IMATERIAL_HPP_*/
