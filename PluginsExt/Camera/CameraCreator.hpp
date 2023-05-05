/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCreator.hpp
*/

#ifndef CAMERACREATOR_HPP_
    #define CAMERACREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "CameraEntity.hpp"

namespace RayTracer::PluginsExt::Camera {
    class CameraCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~CameraCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config) final;

        protected:
        private:
            std::vector<CameraEntity *> _elements;
    };
}

#endif /*CAMERACREATOR_HPP_*/
