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

class Displayable {
	public:
        const std::list<std::unique_ptr<Scenes::ILight>> &getLightList() const;
        std::list<std::unique_ptr<Scenes::ILight>> &getLightList();
        const std::list<std::unique_ptr<Scenes::IPrimitive>> &getPrimitiveList() const;
        std::list<std::unique_ptr<Scenes::IPrimitive>> &getPrimitiveList();

	protected:
	private:
        std::list<std::unique_ptr<Scenes::ILight>> _lights;
        std::list<std::unique_ptr<Scenes::IPrimitive>> _primitives;
};

#endif /*DISPLAYABLE_HPP_*/
