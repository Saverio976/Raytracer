/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
	#define ENTITY_HPP_
    #include "ITransform.hpp"

namespace Scenes {
    class IEntity {
        public:
            ~IEntity() = default;
            ITransform &getTransform();

        protected:
        private:
    };
}

#endif /*ENTITY_HPP_*/
