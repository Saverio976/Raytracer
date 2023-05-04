/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ImagePipeLine.cpp
*/

#include <future>
#include <vector>
#include "ImagePipeLine.hpp"
#include "PixelThread.hpp"

namespace RayTracer::Images {
    ImagePipeLine::ImagePipeLine(RayTracer::Images::Image &image, const Scenes::Displayable &displayable,
        const Scenes::SceneState &state, const RayTracer::Images::RayIterrator &rayIterrator) :
        _image(image),
        _displayable(displayable),
        _state(state),
        _rayIterrator(rayIterrator) { }

    void ImagePipeLine::generate(std::size_t maxThread, std::size_t cluster) {
        std::vector<std::future<void>> threads;
        RayIterrator::iterrator it = ++this->_rayIterrator.begin();
        size_t x = 0;
        size_t y = 0;
        bool stop = false;
        size_t length = this->_image.getSize().getX() * this->_image.getSize().getY();
        maxThread = (maxThread > length) ? length : maxThread;

        while (this->_state.getState() == RayTracer::Scenes::SceneState::States::RUNNING && !stop) {
            if (threads.size() < maxThread) {
                PixelThread pixelThread = PixelThread(this->_displayable, this->_image[y][x], *it);
                threads.push_back(std::async(std::launch::async, pixelThread));
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
            for (auto it = threads.begin(); it != threads.end(); ++it) {
                if (it->wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                    it->get();
                    threads.erase(it);
                    break;
                }
            }
        }
    }

    void ImagePipeLine::apply(Filters::IFilter &filter) {
        filter.apply(this->_image);
    }
}
