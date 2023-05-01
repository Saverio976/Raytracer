/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** RayIterrator.hpp
*/

#ifndef RAYITERATOR_HPP_
    #define RAYITERATOR_HPP_

#include <algorithm>
#include <iterator>
#include "ICamera.hpp"
#include "Ray.hpp"
#include "Vector2i.hpp"
#include "Vector3f.hpp"

namespace RayTracer::Images {
    /**
     * @brief The RayIterrator class
     *
     * class that represent an iterator of a ray
     */
    class RayIterrator {
        public:
            class iterrator {
                public:
                    using iterator_category = std::forward_iterator_tag;
                    using difference_type   = Ray;
                    using value_type        = Ray;
                    using pointer           = Ray *;
                    using reference         = Ray &;

                    iterrator(const Ray &last, const Entities::Transform::Vector2i &size, const Entities::Transform::Vector3f &screenPos, const Entities::Transform::Vector3f &pov);
                    /**
                    * @brief create the next RayIterrator
                    *
                    * @return the next RayIterrator
                    */
                    iterrator operator++();
                    /**
                    * @brief Get the ray of the current RayIterrator
                    *
                    * @return the ray
                    */
                    Ray operator*();
                    /**
                    * @brief Compare two RayIterrator
                    *
                    * @param other the other
                    *
                    * @return true if equal
                    */
                    bool operator==(const RayIterrator::iterrator &other);
                    /**
                    * @brief Compare two RayIterrator
                    *
                    * @param other the other
                    *
                    * @return true if not equal
                    */
                    bool operator!=(const RayIterrator::iterrator &other);
                private:
                    const Ray _last;
                    const Entities::Transform::Vector2i _size;
                    const Entities::Transform::Vector3f _screenPos;
                    const Entities::Transform::Vector3f _pov;
                    Ray _ray;
            };
            /**
             * @brief Constructor
             *
             * @param camera the camera to create the ray itterator
             */
            RayIterrator(const Entities::ICamera &camera);
            RayIterrator::iterrator begin() const;
            RayIterrator::iterrator end() const;

        private:
            const Entities::ICamera &_camera;
            Entities::Transform::Vector3f _pov;
            Ray _beforeFirst;
            Ray _afterLast;
    };
}

#endif
