/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjEntity.hpp
*/
#ifndef OBJENTITY_HPP_
	#define OBJENTITY_HPP_
    #include <functional>
    #include <vector>
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include "ILogger.hpp"
    #include "IPrimitive.hpp"
    #include "Transform.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::PluginsExt::Obj {
    class ObjEntity : public RayTracer::Entities::IPrimitive {
        public:
            class Face {
                public:
                    Face(std::string &faceString);
                    ~Face() = default;
                    const std::vector<int> &getPointsIndexes() const;
                    const std::vector<int> &getNormalsIndexes() const;
                private:
                    std::vector<int> _points;
                    std::vector<int> _normals;
                    std::vector<int> _textures;
            };
            ObjEntity(const Scenes::ISetting &config, ILogger &logger);
            Type getType() const final;
            Entities::Transform::ITransform &getTransform() final;
            const Entities::Transform::ITransform &getTransform() const final;
            bool isCollided(const Entities::Transform::Vector3f &point) const final;
            std::optional<Entities::Transform::Vector3f> isCollided(const Images::Ray &ray) const final;
            Images::Color getColor(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
                const Entities::Transform::Vector3f &intersect) const final;
            Images::Color redirectionLight(const Images::Ray &ray, const Scenes::IDisplayable &displayable,
                const Entities::Transform::Vector3f &intersect) const final;
        private:
            Entities::Transform::Transform _transform;
            std::optional<std::reference_wrapper<Entities::IMaterial>> _material;
            std::vector<Entities::Transform::Vector3f> _pointList;
            std::vector<Entities::Transform::Vector3f> _normalList;
            std::vector<Face> _faceList;
        ILogger &_logger;
    };
}

#endif /*OBJENTITY_HPP_*/
