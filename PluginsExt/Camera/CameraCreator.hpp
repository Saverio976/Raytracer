/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCreator.hpp
*/

#ifndef CAMERACREATOR_HPP_
    #define CAMERACREATOR_HPP_

    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"

namespace RayTracer::PluginsExt::Camera {
    class CameraCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;

        protected:
        private:
    };
}

#endif /*CAMERACREATOR_HPP_*/
