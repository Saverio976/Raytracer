/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** CustomRayIterator.hpp
*/

#ifndef RAYITERATOR_HPP_
    #define RAYITERATOR_HPP_

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <string>
#include "ICamera.hpp"
#include "IRayIterator.hpp"
#include "Ray.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"

namespace RayTracer::PluginsExt::Camera::FullCustom {
    /**
     * @brief The CustomRayIterator class
     *
     * class that represent an iterator of a ray
     */
    class CustomRayIterator : public Images::IRayIterator {
        public:
            class Iterator : public IRayIterator::IIterator {
                public:
                    using iterator_category = std::forward_iterator_tag;
                    using difference_type   = Images::Ray;
                    using value_type        = Images::Ray;
                    using pointer           = Images::Ray *;
                    using reference         = Images::Ray &;

                    Iterator(const Entities::Transform::Vector3f &cameraPos, const Entities::Transform::Vector2i &screenSize, const Entities::Transform::Vector3f &fovXYZ, const Entities::Transform::Vector3f &fov, std::size_t x, std::size_t y);
                    /**
                    * @brief create the next CustomRayIterator
                    *
                    * @return the next CustomRayIterator
                    */
                    IIterator &operator++() final;
                    /**
                    * @brief Get the ray of the current CustomRayIterator
                    *
                    * @return the ray
                    */
                    Images::Ray &operator*() final;
                    /**
                    * @brief Compare two CustomRayIterator
                    *
                    * @param other the other
                    *
                    * @return true if equal
                    */
                    bool operator==(const Images::IRayIterator::IIterator &other) const final;
                    /**
                    * @brief Compare two CustomRayIterator
                    *
                    * @param other the other
                    *
                    * @return true if not equal
                    */
                    bool operator!=(const Images::IRayIterator::IIterator &other) const final;
                    /**
                     * @brief toString
                     *
                     * @return the string
                     */
                    std::string toString() const final;
                    /**
                     * @brief Compare two CustomRayIterator::iterrator
                     *
                     * @param other the other
                     *
                     * @return true if equal
                     */
                    CustomRayIterator::Iterator &operator=(const CustomRayIterator::Iterator &other);
                private:
                    Entities::Transform::Vector3f _cameraPos;
                    Entities::Transform::Vector2i _screenSize;
                    Entities::Transform::Vector3f _fovXYZ;
                    Entities::Transform::Vector3f _fov;
                    std::size_t _x;
                    std::size_t _y;
                    Entities::Transform::Vector3f _normal;
                    Images::Ray _ray;
            };
            /**
             * @brief Constructor
             *
             * @param camera the camera to create the ray itterator
             */
            CustomRayIterator(const Entities::Transform::Vector3f &cameraPos, const Entities::Transform::Vector2i &screenSize, const Entities::Transform::Vector3f &fov, std::size_t unit);
            /**
             * @brief begin of the iterator
             *
             * @return the iterator
             */
            std::unique_ptr<Images::IRayIterator::IIterator> begin() const final;
            /**
             * @brief end of the iterator
             *
             * @return the iterator
             */
            std::unique_ptr<Images::IRayIterator::IIterator> end() const final;

        private:
            Entities::Transform::Vector3f _cameraPos;
            Entities::Transform::Vector2i _screenSize;
            Entities::Transform::Vector3f _fov;
            Entities::Transform::Vector3f _fovXYZ;
    };
}

#endif
