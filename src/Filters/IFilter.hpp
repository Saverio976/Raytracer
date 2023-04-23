/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFilter.hpp
*/

#ifndef IFILTER_HPP_
    #define IFILTER_HPP_

    #include "Image.hpp"

namespace RayTracer::Filters {
    /**
     * @brief The IFilter class
     *
     * class that represent a filter
     */
    class IFilter {
        public:
            virtual ~IFilter() = default;
            /**
             * @brief Apply the filter on an image
             *
             * @param image the image
             */
            virtual void apply(Images::Image &image) = 0;
    };
}

#endif
