/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CylinderCreator.hpp
*/

#ifndef CYLINDER_CREATOR_HPP_
    #define CYLINDER_CREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"
    #include "ISetting.hpp"
    #include "CylinderEntity.hpp"

namespace RayTracer::PluginsExt::Cylinder {
    class CylinderCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~CylinderCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;

        private:
            std::vector<CylinderEntity *> _elements;
    };
}

#endif
