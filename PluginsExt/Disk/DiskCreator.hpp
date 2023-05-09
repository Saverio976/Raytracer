/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DiskCreator.hpp
*/

#ifndef DISKCREATOR_HPP_
    #define DISKCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "DiskEntity.hpp"

namespace RayTracer::PluginsExt::Disk {
    class DiskCreator : public RayTracer::Plugins::Entities::IEntityCreator {
        public:
            ~DiskCreator();
            RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
        protected:
        private:
            std::vector<DiskEntity *> _elements;
    };
}

#endif
