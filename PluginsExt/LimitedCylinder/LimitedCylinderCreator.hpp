/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LimitedCylinderCreator.hpp
*/

#ifndef CYLINDER_CREATOR_HPP_
    #define CYLINDER_CREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "ISetting.hpp"
    #include "ISetting.hpp"
    #include "LimitedCylinderEntity.hpp"

namespace RayTracer::PluginsExt::LimitedCylinder {
    class LimitedCylinderCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~LimitedCylinderCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;

        private:
            std::vector<LimitedCylinderEntity *> _elements;
    };
}

#endif
