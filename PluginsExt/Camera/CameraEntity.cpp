/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include <iostream>
#include "CameraEntity.hpp"
#include "FilterFactory.hpp"
#include "ImagePipeLine.hpp"
#include "SettingWrapper.hpp"

namespace RayTracer::PluginsExt::Camera {

    CameraEntity::CameraEntity(const Scenes::ISetting &config) :
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _size(Entities::Transform::Vector2i(*config.get("size"))),
        _image(Images::Image(Entities::Transform::Vector2i(*config.get("size"))))
    {
        std::unique_ptr<Scenes::ISetting> tmp = config.get("focal");

        this->_focal = static_cast<double>(*tmp);
        try {
            std::shared_ptr<Scenes::ISetting> settingWrapper = config.get("filter");
            std::unique_ptr<Scenes::ISetting> tmp;

            for (int i = 0; i < settingWrapper->getLength(); i++) {
                tmp = settingWrapper->get(i);
                _filters.push_back(Factories::FilterFactory::get(tmp->getKey(), *tmp));
            }
        } catch (const Scenes::SettingWrapper::ParsingException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            _maxThread = static_cast<int>(*config.get("maxThreads"));
            _maxThread = (_maxThread == -1) ? std::thread::hardware_concurrency() : _maxThread;
        } catch (const Scenes::SettingWrapper::ParsingException &e) {
            _maxThread = std::thread::hardware_concurrency();
        }
        _maxThread = (_maxThread <= 0) ? 1 : _maxThread;
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

    double CameraEntity::getFocal() const {
        return this->_focal;
    }

    void CameraEntity::setFocal(double value) {
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
        Images::ImagePipeLine imagePipeLine(this->_image, displayable, state, iterator);

        imagePipeLine.generate(_maxThread, 1);
        for (const std::reference_wrapper<Filters::IFilter> &filter : this->_filters) {
            imagePipeLine.apply(filter.get());
        }
        return this->_image;
    }

    const Images::Image &CameraEntity::getImage() const {
        return this->_image;
    }

    std::list<std::reference_wrapper<Filters::IFilter>> &CameraEntity::getFilters() {
        return this->_filters;
    }
}
