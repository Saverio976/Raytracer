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
    class IFilter {
        public:
            virtual ~IFilter() = default;
            virtual void apply(Images::Image &image) = 0;
    };
}

#endif
