/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include <iostream>
#include <thread>
#include "ILogger.hpp"
#include "ISceneState.hpp"
#include "IDisplayable.hpp"
#include "CameraEntity.hpp"
#include "IFilterFactory.hpp"
#include "ImagePipeLine.hpp"

namespace RayTracer::PluginsExt::Camera {

    CameraEntity::CameraEntity(const Scenes::ISetting &config, ILogger &logger):
        _transform(Entities::Transform::Transform(*config.get("transform"))),
        _size(Entities::Transform::Vector2i(*config.get("size"))),
        _image(Images::Image(Entities::Transform::Vector2i(*config.get("size")))),
        _logger(logger)
    {
        std::unique_ptr<Scenes::ISetting> tmp = config.get("focal");

        this->_focal = static_cast<double>(*tmp);
        try {
            std::shared_ptr<Scenes::ISetting> settingWrapper = config.get("filter");
            std::unique_ptr<Scenes::ISetting> tmp;

            for (int i = 0; i < settingWrapper->getLength(); i++) {
                tmp = settingWrapper->get(i);
                _filters.push_back(getFilterFactoryInstance()->get(tmp->getKey(), *tmp, logger));
            }
        } catch (const Scenes::ISetting::IParsingException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            _maxThread = static_cast<int>(*config.get("maxThreads"));
            _maxThread = (_maxThread == -1) ? std::thread::hardware_concurrency() : _maxThread;
        } catch (const Scenes::ISetting::IParsingException &e) {
            _maxThread = std::thread::hardware_concurrency();
        }
        _maxThread = (_maxThread <= 0) ? 1 : _maxThread;
        _logger.info("Max threads : " + std::to_string(_maxThread));
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

    const Images::Image &CameraEntity::render(const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state) {
        Images::RayIterrator iterator(*this);
        Images::ImagePipeLine imagePipeLine(this->_image, displayable, state, iterator);

        imagePipeLine.generate(_logger, _maxThread, 1);
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
