/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ImagePipeLine.cpp
*/

#include "ImagePipeLine.hpp"
#include "PixelThread.hpp"
#include <thread>
#include <vector>

namespace RayTracer::Images {
    ImagePipeLine::ImagePipeLine(RayTracer::Images::Image &image, const Scenes::Displayable &displayable,
        const Scenes::SceneState &state, const RayTracer::Images::RayIterrator &rayIterrator) :
        _image(image),
        _displayable(displayable),
        _state(state),
        _rayIterrator(rayIterrator) { }

    void ImagePipeLine::generate(std::size_t maxThread, std::size_t cluster) {
        std::vector<std::thread> threads;

        for (size_t i = 0; i < maxThread; i++)
            threads.push_back(std::thread());
    }

    void ImagePipeLine::apply(Filters::IFilter &filter) {
        filter.apply(this->_image);
    }
}