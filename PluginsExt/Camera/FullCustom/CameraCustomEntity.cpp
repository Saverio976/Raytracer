/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCustom.cpp
*/

#include <iostream>
#include <string>
#include <thread>
#include "ILogger.hpp"
#include "ISceneState.hpp"
#include "IDisplayable.hpp"
#include "CustomRayIterator.hpp"
#include "CameraCustomEntity.hpp"
#include "IFilterFactory.hpp"
#include "ISetting.hpp"
#include "Image.hpp"
#include "ImagePipeLine.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Camera::FullCustom {

    CameraCustomEntity::CameraCustomEntity(const Scenes::ISetting &config, ILogger &logger):
        _positionCamera(Entities::Transform::Transform(*config.get("positionCamera"))),
        _screenSize(Entities::Transform::Vector2i(*config.get("screenSize"))),
        _logger(logger)
    {
        try {
            std::unique_ptr<Scenes::ISetting> settingWrapper = config.get("filters");
            std::unique_ptr<Scenes::ISetting> tmp;
            int length = settingWrapper->getLength();
            for (int i = 0; i < length; i++) {
                int length_two = (*settingWrapper).get(i)->getLength();
                std::string name = (*settingWrapper).get(i)->getKey();
                for (int j = 0; j < length_two; j++) {
                    tmp = settingWrapper->get(i)->get(j);
                    _filters.push_back(static_cast<Filters::IFilter &>(getFilterFactoryInstance()->get(name, *tmp, _logger)));
                }
            }
        } catch (const Scenes::ISetting::IParsingException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            _maxThread = static_cast<int>(*config.get("maxThreads"));
            _maxThread = (_maxThread == -1) ? std::thread::hardware_concurrency() : _maxThread;
        } catch (const Scenes::ISetting::IParsingException &e) {
            _maxThread = std::thread::hardware_concurrency();
        } catch (const Scenes::ISetting::ITypeException &e) {
            _maxThread = std::thread::hardware_concurrency();
        }
        _maxThread = (_maxThread <= 0) ? 1 : _maxThread;
        _logger.info("CameraCustom Max threads : " + std::to_string(_maxThread));
        if (getTransform().getScale().getX() != 0 || getTransform().getScale().getY() != 0 || getTransform().getScale().getZ() != 0) {
            _logger.warn("CAMERA: config: scale x y z must be 0 (not suported to scale camera)");
        }
        _image = Images::Image(_screenSize);
    }

    Entities::IEntity::Type CameraCustomEntity::getType() const
    {
        return Type::Camera;
    }

    Entities::Transform::ITransform &CameraCustomEntity::getTransform()
    {
        return this->_positionCamera;
    }

    const Entities::Transform::ITransform &CameraCustomEntity::getTransform() const
    {
        return this->_positionCamera;
    }

    double CameraCustomEntity::getFocal() const
    {
        return _fov;
    }

    void CameraCustomEntity::setFocal(double value)
    {
        _fov = value;
    }

    void CameraCustomEntity::setSize(const Entities::Transform::Vector2i &vector)
    {
        this->_screenSize = vector;
    }

    const Entities::Transform::Vector2i &CameraCustomEntity::getSize() const
    {
        return this->_screenSize;
    }

    const Images::Image &CameraCustomEntity::render(const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state)
    {
        CustomRayIterator iterator(this->_positionCamera.getPosition(), this->_screenSize, this->_positionCamera.getRotation(), 1);
        Images::ImagePipeLine imagePipeLine(this->_image.value(), displayable, state, iterator);

        imagePipeLine.generate(_logger, _maxThread, 1);
        for (const auto &filter : this->_filters) {
            imagePipeLine.apply(filter.get());
        }
        return this->_image.value();
    }

    const Images::Image &CameraCustomEntity::getImage() const
    {
        return this->_image.value();
    }

    std::list<std::reference_wrapper<Filters::IFilter>> &CameraCustomEntity::getFilters()
    {
        return this->_filters;
    }
}
