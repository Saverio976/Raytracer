/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ImagePipeLine.cpp
*/

#include <future>
#include <vector>
#include "ILogger.hpp"
#include "Progress.hpp"
#include "ImagePipeLine.hpp"
#include "PixelThread.hpp"

namespace RayTracer::Images {
    ImagePipeLine::ImagePipeLine(RayTracer::Images::Image &image, const Scenes::IDisplayable &displayable,
        const Scenes::ISceneState &state, const RayTracer::Images::IRayIterator &rayIterrator) :
        _image(image),
        _displayable(displayable),
        _state(state),
        _rayIterrator(rayIterrator)
    {
    }

    void ImagePipeLine::generate(ILogger &logger, std::size_t maxThread, std::size_t cluster) {
        std::vector<std::future<void>> threads;
        auto start = this->_rayIterrator.begin();
        auto &it = *start;
        size_t x = 0;
        size_t y = 0;
        bool stop = false;
        size_t length = this->_image.getSize().getX() * this->_image.getSize().getY();
        maxThread = (maxThread > length) ? length : maxThread;
        Progress progress(length, 0.05, logger);

        while (this->_state.getState() == RayTracer::Scenes::ISceneState::States::RUNNING && !stop) {
            if (threads.size() < maxThread) {
                PixelThread pixelThread = PixelThread(this->_displayable, this->_image[y][x], *it);
                threads.push_back(std::async(std::launch::async, pixelThread));
                ++it;
                x++;
                if (x >= this->_image.getSize().getX()) {
                    x = 0;
                    y++;
                }
                if (y >= this->_image.getSize().getY() || it == *_rayIterrator.end()) {
                    stop = true;
                    break;
                }
            }
            for (auto it2 = threads.begin(); it2 != threads.end(); ++it2) {
                if (it2->wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                    it2 = threads.erase(it2);
                    progress.add(cluster);
                    break;
                }
            }
        }
        while (!threads.empty()) {
            for (auto it = threads.begin(); it != threads.end(); ++it) {
                if (it->wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                    it = threads.erase(it);
                    progress.add(cluster);
                    break;
                }
            }
        }
        progress.add(length);
    }

    void ImagePipeLine::apply(Filters::IFilter &filter) {
        filter.apply(this->_image);
    }
}
