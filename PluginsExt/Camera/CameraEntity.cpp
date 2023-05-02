/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "CameraEntity.hpp"
#include "FilterFactory.hpp"
#include "ImagePipeLine.hpp"

namespace RayTracer::PluginsExt::Camera {

    CameraEntity::CameraEntity(const Scenes::ISetting &config) :
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _size(Entities::Transform::Vector2i(*config.get("size"))),
        _focal(*config.get("focal")),
        _image(Images::Image(_size)) {
        try {
            std::shared_ptr<ISetting> settingWrapper = config.get("filter");
            std::unique_ptr<ISetting> tmp;

            for (int i = 0; i < settingWrapper->getLength(); i++) {
                tmp = settingWrapper->get(i);
                std::unique_ptr<Filters::IFilter> filterPtr(Factories::FilterFactory::get(tmp->getKey(), *tmp));

                _filters.push_back(std::move(filterPtr));
            }
        } catch (const libconfig::ParseException &e) { }
    }

    Entities::IEntity::Type CameraEntity::getType() const {
        return Type::Camera;
    }

    Entities::Transform::ITransform &CameraEntity::getTransform() {
        return this->_transform;
    }

    const Entities::Transform::ITransform &CameraEntity::getTransform() const {
        return this->_transform;
    }

    float CameraEntity::getFocal() const {
        return this->_focal;
    }

    void CameraEntity::setFocal(float value) {
        this->_focal = value;
    }

    void CameraEntity::setSize(const Entities::Transform::Vector2i &vector) {
        this->_size = vector;
    }

    const Entities::Transform::Vector2i &CameraEntity::getSize() const {
        return this->_size;
    }

    const Images::Image &CameraEntity::render(const Scenes::Displayable &displayable, const Scenes::SceneState &state) {
        Images::RayIterrator iterator(*this);
        Images::ImagePipeLine::ImagePipeLine imagePipeLine(this->_image, displayable, state, iterator);

        imagePipeLine.generate(1, 1);
        for (const IFilter &filter : this->_filters) {
            imagePipeLine.apply(filter);
        }
        return this->_image;
    }

    const Images::Image &CameraEntity::getImage() const {
        return this->_image;
    }

    std::list<std::unique_ptr<Filters::IFilter>> &CameraEntity::getFilters() {
        return this->_filters;
    }
}