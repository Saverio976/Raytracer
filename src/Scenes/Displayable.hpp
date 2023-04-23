/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Displayable.hpp
*/

#ifndef DISPLAYABLE_HPP_
	#define DISPLAYABLE_HPP_

    #include "ILight.hpp"
    #include "IPrimitive.hpp"
    #include <list>
    #include <memory>

namespace RayTracer::Scenes {
    class Displayable {
    public:
        const std::list<std::unique_ptr<Entities::ILight>> &getLightList() const;
        std::list<std::unique_ptr<Entities::ILight>> &getLightList();
        const std::list<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList() const;
        std::list<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList();

    protected:
    private:
        std::list<std::unique_ptr<Entities::ILight>> _lights;
        std::list<std::unique_ptr<Entities::IPrimitive>> _primitives;
    };
}

#endif /*DISPLAYABLE_HPP_*/
