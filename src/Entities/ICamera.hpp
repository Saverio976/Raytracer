/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ICamera.hpp
*/

#ifndef ICAMERA_HPP_
    #define ICAMERA_HPP_
    #include <cstddef>
#include <list>
    #include "Transform/Vector2i.hpp"
    #include "IDisplayable.hpp"
    #include "Image.hpp"
    #include "IFilter.hpp"
    #include "ISceneState.hpp"
    #include "IEntity.hpp"

namespace RayTracer::Entities {
    /**
     * @brief The ICamera class
     *
     * class that represent a camera
     * (perspective, orthographic, panoramic, ...)
     */
    class ICamera : public IEntity {
        public:
            virtual ~ICamera() = default;
            /**
             * @brief Get the focal (distance from the camera)
             *
             * @return the focal
             */
            virtual double getFocal() const = 0;
            /**
             * @brief Set the focal (distance from the camera)
             *
             * @param value the focal
             */
            virtual void setFocal(double value) = 0;
            /**
             * @brief Set the size (of the screen)
             *
             * @param vector the size
             */
            virtual void setSize(const Transform::Vector2i &vector) = 0;
            /**
             * @brief Get the size (of the screen)
             *
             * @return the size
             */
            virtual const Transform::Vector2i &getSize() const = 0;
            /**
             * @brief Render an image
             *
             * @param displayable the displayable
             * @param state the state (if cancel needed)
             *
             * @return the image
             */
            virtual const Images::Image &render(const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state) = 0;
            /**
             * @brief Get the image (possible when rendering)
             *
             * @return the image
             */
            virtual const Images::Image &getImage() const = 0;
            /**
             * @brief Get the filters
             *
             * @return the filters
             */
            virtual std::list<std::reference_wrapper<Filters::IFilter>> &getFilters() = 0;
            /**
             * @brief Set the cluster (1 is more precision, +infini is less precision)
             *
             * @param cluster the cluster
             */
            virtual void setCluster(std::size_t cluster) = 0;
            /**
             * @brief Get the cluster
             */
            virtual std::size_t getCluster() const = 0;

        protected:
        private:
    };
}

#endif /*ICAMERA_HPP_*/
