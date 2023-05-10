/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** RayIterrator.hpp
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

namespace RayTracer::Images {
    /**
     * @brief The RayIterrator class
     *
     * class that represent an iterator of a ray
     */
    class RayIterrator : public IRayIterator {
        public:
            class Iterrator : public IRayIterator::IIterator {
                public:
                    using iterator_category = std::forward_iterator_tag;
                    using difference_type   = Ray;
                    using value_type        = Ray;
                    using pointer           = Ray *;
                    using reference         = Ray &;

                    Iterrator(
                            const Ray &last,
                            const Entities::Transform::Vector2i &size,
                            const Entities::Transform::Vector3f &screenPos,
                            const Entities::Transform::Vector3f &pov);
                    /**
                    * @brief create the next RayIterrator (modify current instance)
                    *
                    * @return the current instance modified
                    */
                    IIterator &operator++() final;
                    /**
                    * @brief Get the ray of the current RayIterrator
                    *
                    * @return the ray
                    */
                    Ray &operator*() final;
                    /**
                    * @brief Compare two RayIterrator
                    *
                    * @param other the other
                    *
                    * @return true if equal
                    */
                    bool operator==(const IRayIterator::IIterator &other) const final;
                    /**
                    * @brief Compare two RayIterrator
                    *
                    * @param other the other
                    *
                    * @return true if not equal
                    */
                    bool operator!=(const IRayIterator::IIterator &other) const final;
                    /**
                     * @brief Compare two RayIterrator::iterrator
                     *
                     * @param other the other
                     *
                     * @return true if equal
                     */
                    RayIterrator::Iterrator &operator=(const RayIterrator::Iterrator &other);
                    /**
                     * @brief toString
                     *
                     * @return the string
                     */
                    std::string toString() const final;
                private:
                    const Ray _last;
                    const Entities::Transform::Vector2i _size;
                    const Entities::Transform::Vector3f _screenPos;
                    const Entities::Transform::Vector3f _pov;
                    Ray _ray;
                    std::size_t _cluster;
            };
            /**
             * @brief Constructor
             *
             * @param camera the camera to create the ray itterator
             */
            RayIterrator(const Entities::ICamera &camera);
            std::unique_ptr<IRayIterator::IIterator> begin() const final;
            std::unique_ptr<IRayIterator::IIterator> end() const final;

        private:
            const Entities::ICamera &_camera;
            Entities::Transform::Vector3f _pov;
            Ray _beforeFirst;
            Ray _afterLast;
            std::size_t _cluster;
    };
}

#endif
