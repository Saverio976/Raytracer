/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraCustom.hpp
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include <functional>
    #include <optional>
    #include "ICamera.hpp"
    #include "ILogger.hpp"
    #include "ISceneState.hpp"
    #include "IDisplayable.hpp"
    #include "Transform.hpp"
    #include "Vector2i.hpp"
    #include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Camera::FullCustom {
    class CameraCustomEntity : public RayTracer::Entities::ICamera {
        public:
            CameraCustomEntity(const Scenes::ISetting &config, ILogger &logger);
            ~CameraCustomEntity() = default;
            Type getType() const final;
            Entities::Transform::ITransform &getTransform() final;
            const Entities::Transform::ITransform &getTransform() const final;
            /**
              * @brief Get the focal (distance from the camera)
              *
              * @return the focal
              */
            double getFocal() const final;
            /**
             * @brief Set the focal (distance from the camera)
             *
             * @param value the focal
             */
            void setFocal(double value) final;
            /**
             * @brief Set the size (of the screen)
             *
             * @param vector the size
             */
            void setSize(const Entities::Transform::Vector2i &vector) final;
            /**
             * @brief Get the size (of the screen)
             *
             * @return the size
             */
            const Entities::Transform::Vector2i &getSize() const final;
            /**
             * @brief Render an image
             *
             * @param displayable the displayable
             * @param state the state (if cancel needed)
             *
             * @return the image
             */
            const Images::Image &render(const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state) final;
            /**
             * @brief Get the image (possible when rendering)
             *
             * @return the image
             */
            const Images::Image &getImage() const final;
            /**
             * @brief Get the filters
             *
             * @return the filters
             */
            std::list<std::reference_wrapper<Filters::IFilter>> &getFilters() final;

        protected:
        private:
            Entities::Transform::Transform _positionCamera;
            Entities::Transform::Vector2i _screenSize;
            double _fov;
            std::optional<Images::Image> _image;
            std::list<std::reference_wrapper<Filters::IFilter>> _filters;
            int _maxThread;
            ILogger &_logger;
    };
}

#endif /*CAMERA_HPP_*/
