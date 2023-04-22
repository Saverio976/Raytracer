/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef IMATERIAL_HPP_
	#define IMATERIAL_HPP_
    #include "Color.hpp"

namespace Scenes {
    class IMaterial {
        public:
            ~IMaterial() = default;
            const Color &getColor() const;
            void setColor(const Color &color);

        protected:
        private:
    };
}

#endif /*IMATERIAL_HPP_*/
