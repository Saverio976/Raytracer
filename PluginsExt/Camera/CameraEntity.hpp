/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.hpp
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include <functional>
    #include "ICamera.hpp"
    #include "Transform.hpp"

namespace RayTracer::PluginsExt::Camera {
    class CameraEntity : public RayTracer::Entities::ICamera {
        public:
            CameraEntity(const Scenes::ISetting &config);
            ~CameraEntity() = default;
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
            const Images::Image &render(const Scenes::Displayable &displayable, const Scenes::SceneState &state) final;
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
            Images::Image _image;
            Entities::Transform::Vector2i _size;
            double _focal;
            std::list<std::reference_wrapper<Filters::IFilter>> _filters;
            Entities::Transform::Transform _transform;
            int _maxThread;
    };
}

#endif /*CAMERA_HPP_*/
