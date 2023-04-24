/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** RayIterrator.hpp
*/

#ifndef RAYITERATOR_HPP_
    #define RAYITERATOR_HPP_

#include "ICamera.hpp"
#include "Ray.hpp"

namespace RayTracer::Images {
    /**
     * @brief The RayIterrator class
     *
     * class that represent an iterator of a ray
     */
    class RayIterrator {
        public:
            /**
             * @brief Constructor
             *
             * @param camera the camera to create the ray itterator
             */
            RayIterrator(const Entities::ICamera &camera);
            /**
             * @brief create the next RayIterrator
             *
             * @return the next RayIterrator
             */
            RayIterrator operator++();
            /**
             * @brief Get the ray of the current RayIterrator
             *
             * @return the ray
             */
            Ray operator*();
            /**
             * @brief Reset the current RayIterrator
             */
            void reset();

        private:
            const Entities::ICamera &_camera;
    };
}

#endif
