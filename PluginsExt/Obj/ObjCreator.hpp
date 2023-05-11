/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjCreator.hpp
*/

#ifndef OBJCREATOR_HPP_
	#define OBJCREATOR_HPP_
    #include <vector>
    #include <memory>
    #include "IEntityCreator.hpp"
    #include "ILogger.hpp"
    #include "ObjEntity.hpp"

namespace RayTracer::PluginsExt::Obj {
    class ObjCreator : public RayTracer::Plugins::Entities::IEntityCreator {
    public:
        ~ObjCreator();
        RayTracer::Entities::IEntity *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<ObjEntity *> _elements;
    };
}
#endif /*OBJCREATOR_HPP_*/
