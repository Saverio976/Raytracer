/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ImagePipeLine.cpp
*/

#include "ImagePipeLine.hpp"

namespace RayTracer::Images {
    ImagePipeLine::ImagePipeLine(RayTracer::Images::Image &image, const Scenes::Displayable &displayable,
        const Scenes::SceneState &state, const RayTracer::Images::RayIterrator &rayIterrator) :
        _image(image),
        _displayable(displayable),
        _state(state),
        _rayIterrator(rayIterrator) { }

    void ImagePipeLine::generate(std::size_t maxThread, std::size_t cluster) {

    }

    void ImagePipeLine::apply(Filters::IFilter &filter) {

    }
}