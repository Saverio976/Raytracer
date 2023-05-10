/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCluster.cpp
*/

#include <string>
#include <thread>
#include "ILogger.hpp"
#include "ISceneState.hpp"
#include "IDisplayable.hpp"
#include "ClusterRayIterator.hpp"
#include "CameraClusterEntity.hpp"
#include "IFilterFactory.hpp"
#include "ISetting.hpp"
#include "Image.hpp"
#include "ImagePipeLine.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Camera::Clustered {

    CameraClusterEntity::CameraClusterEntity(const Scenes::ISetting &config, ILogger &logger):
        _screen(Entities::Transform::Transform(*config.get("screen"))),
        _screenSize(Entities::Transform::Vector2i(*config.get("screenSize"))),
        _fov(*config.get("distanceFromScreen")),
        _cluster(*config.get("cluster")),
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
            _logger.error("CAMERA_CUSTOM: " + std::string(e.what()));
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
        _logger.info("CameraCluster Max threads : " + std::to_string(_maxThread));
        if (getTransform().getScale().getX() != 0 || getTransform().getScale().getY() != 0 || getTransform().getScale().getZ() != 0) {
            _logger.warn("CAMERA: config: scale x y z must be 0 (not suported to scale camera)");
        }
        _image = Images::Image(_screenSize);
    }

    Entities::IEntity::Type CameraClusterEntity::getType() const
    {
        return Type::Camera;
    }

    Entities::Transform::ITransform &CameraClusterEntity::getTransform()
    {
        return this->_screen;
    }

    const Entities::Transform::ITransform &CameraClusterEntity::getTransform() const
    {
        return this->_screen;
    }

    double CameraClusterEntity::getFocal() const
    {
        return _fov;
    }

    void CameraClusterEntity::setFocal(double value)
    {
        _fov = value;
    }

    void CameraClusterEntity::setSize(const Entities::Transform::Vector2i &vector)
    {
        this->_screenSize = vector;
    }

    const Entities::Transform::Vector2i &CameraClusterEntity::getSize() const
    {
        return this->_screenSize;
    }

    const Images::Image &CameraClusterEntity::render(const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state)
    {
        Entities::Transform::Vector3f positionCamera = this->_screen.getPosition() - Entities::Transform::Vector3f(0, this->getFocal(), 0);
        ClusterRayIterator iterr(positionCamera, this->_screen.getPosition(), this->_screenSize, _cluster);
        Images::ImagePipeLine imagePipeLine(this->_image.value(), displayable, state, iterr);

        imagePipeLine.generate(_logger, _maxThread, _cluster);
        for (const auto &filter : this->_filters) {
            imagePipeLine.apply(filter.get());
        }
        return this->_image.value();
    }

    const Images::Image &CameraClusterEntity::getImage() const
    {
        return this->_image.value();
    }

    std::list<std::reference_wrapper<Filters::IFilter>> &CameraClusterEntity::getFilters()
    {
        return this->_filters;
    }
}
