/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCustomCreator.hpp
*/

#ifndef CAMERACREATOR_HPP_
    #define CAMERACREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "CameraCustomEntity.hpp"

namespace RayTracer::PluginsExt::Camera::FullCustom {
    class CameraCustomCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~CameraCustomCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;

        protected:
        private:
            std::vector<CameraCustomEntity *> _elements;
    };
}

#endif /*CAMERACREATOR_HPP_*/
