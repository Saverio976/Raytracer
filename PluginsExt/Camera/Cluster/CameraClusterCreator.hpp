/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraClusterCreator.hpp
*/

#ifndef CAMERACREATOR_HPP_
    #define CAMERACREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "CameraClusterEntity.hpp"

namespace RayTracer::PluginsExt::Camera::Clustered {
    class CameraClusterCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~CameraClusterCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;

        protected:
        private:
            std::vector<CameraClusterEntity *> _elements;
    };
}

#endif /*CAMERACREATOR_HPP_*/
