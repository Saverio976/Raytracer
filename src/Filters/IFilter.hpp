/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFilter.hpp
*/

#ifndef IFILTER_HPP_
    #define IFILTER_HPP_

    #include "Image.hpp"

class IFilter {
    public:
        virtual ~IFilter() = default;
        virtual void apply(Image &image) = 0;
};

#endif
