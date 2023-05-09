/*_
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntityHandler.cpp
*/

#include "EntityHandler.hpp"
#include "ILogger.hpp"

namespace RayTracer::Plugins::Entities {
    EntityHandler::EntityHandler(const std::string &filePath) : _handler(filePath) { }

    RayTracer::Entities::IEntity &EntityHandler::get(const RayTracer::Scenes::ISetting &setting, ILogger &logger) {
        return this->_handler.get(setting, logger);
    }
}
