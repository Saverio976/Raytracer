/*_
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntityHandler.cpp
*/

#include "EntityHandler.hpp"

namespace RayTracer::Plugins::Entities {
    EntityHandler::EntityHandler(const std::string &filePath) : _handler(filePath) { }

    std::unique_ptr <RayTracer::Entities::IEntity> EntityHandler::get(const RayTracer::Scenes::ISetting &setting) const {
        return this->_handler.get(setting);
    }
}
