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
        RayIterrator::iterrator it = ++this->_rayIterrator.begin();
        size_t x = 0;
        size_t y = 0;
        bool stop = false;
        size_t length = this->_image.getSize().getX() * this->_image.getSize().getY();
        maxThread = (maxThread > length) ? length : maxThread;

        for (size_t i = 0; i < maxThread; i++)
            threads.push_back(std::thread());
        while (this->_state.getState() == RayTracer::Scenes::SceneState::States::RUNNING && !stop) {
            for (std::thread &thread : threads) {
                PixelThread pixelThread = PixelThread(this->_displayable, this->_image[y][x], *it);
                thread = std::thread(pixelThread);
                it = ++it;
                x++;
                if (x >= this->_image.getSize().getX()) {
                    x = 0;
                    y++;
                }
                if (y >= this->_image.getSize().getY() || it == _rayIterrator.end()) {
                    stop = true;
                    break;
                }
            }
            for (std::thread &thread : threads) {
                thread.join();
            }
        }
    }

    void ImagePipeLine::apply(Filters::IFilter &filter) {
        filter.apply(this->_image);
    }
}
