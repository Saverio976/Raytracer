/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ClusterRayIterator.hpp
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

namespace RayTracer::PluginsExt::Camera::Clustered {
    /**
     * @brief The ClusterRayIterator class
     *
     * class that represent an iterator of a ray
     */
    class ClusterRayIterator : public Images::IRayIterator {
        public:
            class Iterator : public IRayIterator::IIterator {
                public:
                    using iterator_category = std::forward_iterator_tag;
                    using difference_type   = Images::Ray;
                    using value_type        = Images::Ray;
                    using pointer           = Images::Ray *;
                    using reference         = Images::Ray &;

                    Iterator(
                            const Entities::Transform::Vector3f &cameraPos,
                            const Entities::Transform::Vector2i &screenSize,
                            const Entities::Transform::Vector3f &screenPosCenter,
                            std::size_t x,
                            std::size_t y,
                            std::size_t cluster);
                    /**
                    * @brief create the next ClusterRayIterator
                    *
                    * @return the next ClusterRayIterator
                    */
                    IIterator &operator++() final;
                    /**
                    * @brief Get the ray of the current ClusterRayIterator
                    *
                    * @return the ray
                    */
                    Images::Ray &operator*() final;
                    /**
                    * @brief Compare two ClusterRayIterator
                    *
                    * @param other the other
                    *
                    * @return true if equal
                    */
                    bool operator==(const Images::IRayIterator::IIterator &other) const final;
                    /**
                    * @brief Compare two ClusterRayIterator
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
                     * @brief Compare two ClusterRayIterator::iterrator
                     *
                     * @param other the other
                     *
                     * @return true if equal
                     */
                    ClusterRayIterator::Iterator &operator=(const ClusterRayIterator::Iterator &other);
                private:
                    Entities::Transform::Vector3f _cameraPos;
                    Entities::Transform::Vector2i _screenSize;
                    Entities::Transform::Vector3f _screenPosTopLeft;
                    std::size_t _cluster;
                    std::size_t _x;
                    std::size_t _y;
                    Images::Ray _ray;
            };
            /**
             * @brief Constructor
             *
             * @param camera the camera to create the ray itterator
             */
            ClusterRayIterator(
                    const Entities::Transform::Vector3f &cameraPos,
                    const Entities::Transform::Vector3f &screenPosCenter,
                    const Entities::Transform::Vector2i &screenSize,
                    std::size_t unit);
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
            Entities::Transform::Vector3f _screenPosCenter;
            Entities::Transform::Vector3f _screenPosTopLeft;
            Entities::Transform::Vector2i _screenSize;
            std::size_t _unit;
    };
}

#endif
