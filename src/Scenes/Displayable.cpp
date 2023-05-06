/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Displayable.cpp
*/

#include "Displayable.hpp"
#include "ILight.hpp"

namespace RayTracer::Scenes {

    Displayable::DisplayableException::DisplayableException(const std::string &key) {
        _msg = "Displayable error : " + key;
    };

    const char *Displayable::DisplayableException::what() const throw() {
        return _msg.c_str();
    }

    const std::vector<std::reference_wrapper<Entities::ILight>> &Displayable::getLightList() const {
        return _lights;
    }

    std::vector<std::reference_wrapper<Entities::ILight>> &Displayable::getLightList() {
        return _lights;
    }

    const std::vector<std::reference_wrapper<Entities::IPrimitive>> &Displayable::getPrimitiveList() const {
        return _primitives;
    }

    std::vector<std::reference_wrapper<Entities::IPrimitive>> &Displayable::getPrimitiveList() {
        return _primitives;
    }

    Entities::ILight &Displayable::getAmbientLight() {
        for (Entities::ILight &light : this->_lights)
            if (light.isAmbient())
                return light;
        throw Displayable::DisplayableException("Empty Ambient");
    }

    const Entities::ILight &Displayable::getAmbientLight() const {
        for (const Entities::ILight &light : this->_lights)
            if (light.isAmbient())
                return light;
        throw Displayable::DisplayableException("Empty Ambient");
    }
}
