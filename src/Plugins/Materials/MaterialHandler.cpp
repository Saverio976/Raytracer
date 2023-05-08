/*_
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EntityHandler.cpp
*/

#include "MaterialHandler.hpp"
#include "ILogger.hpp"

namespace RayTracer::Plugins::Materials {
    MaterialHandler::MaterialHandler(const std::string &filePath) : _handler(filePath) { }

    RayTracer::Entities::IMaterial &MaterialHandler::get(const RayTracer::Scenes::ISetting &setting, ILogger &logger) {
        return this->_handler.get(setting, logger);
    }
}
