
/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SSAAx4Entity.hpp
*/

#include <exception>
#include <future>
#include "Color.hpp"
#include "ILogger.hpp"
#include "IFilter.hpp"
#include "ISetting.hpp"
#include "Image.hpp"
#include "SSAAx4Entity.hpp"
#include "Vector2i.hpp"

namespace RayTracer::PluginsExt::AntiAliasing::SSAAx4 {
    SSAAx4Entity::SSAAx4Entity(const Scenes::ISetting &config, ILogger &logger):
        _logger(logger)
    {
        try {
            _maxThread = static_cast<int>(*config.get("maxThreads"));
            _maxThread = (_maxThread == -1) ? std::thread::hardware_concurrency() : _maxThread;
        } catch (const Scenes::ISetting::IParsingException &e) {
            _maxThread = std::thread::hardware_concurrency();
        }
        _maxThread = (_maxThread <= 0) ? 1 : _maxThread;
        _logger.info("Max threads : " + std::to_string(_maxThread));
    }

    void SSAAx4Entity::waitOnePlace()
    {
        while (_futures.size() >= _maxThread) {
            for (auto it = _futures.begin() ; it != _futures.end(); it++) {
                if ((*it).wait_for(std::chrono::milliseconds(1)) == std::future_status::ready) {
                    _futures.erase(it);
                    break;
                }
            }
        }
    }

    void SSAAx4Entity::apply(Images::Image &image)
    {
        _logger.info("Applying SSAAx4 Anti-Aliasing...");
        Images::Image tmp(image.getSize() * Entities::Transform::Vector2i(2, 2));
        Images::Image newImage(image.getSize() * Entities::Transform::Vector2i(2, 2));

        for (int x = 0; x < tmp.getSize().getX(); x++) {
            this->waitOnePlace();
            _futures.push_back(std::async(std::launch::deferred, [&tmp, x, &image]() {
                for (int y = 0; y < tmp.getSize().getY(); y++) {
                    tmp[y][x] = image[y / 2][x / 2];
                }
            }));
        }
        for (int x = 0; x < newImage.getSize().getX() && x < tmp.getSize().getX(); x++) {
            for (int y = 0; y < newImage.getSize().getY() && y < tmp.getSize().getY(); y++) {
                // -------------------------------------------------------
                // This is not in another function because i try it and
                // it caused a wild error.
                // See commit 76b7b4b524748a57bd459766e1224ddcc6cef00b
                // (in this commit add modified the test to run).
                // See commit 244e36ac46b80ec5f58fa23e2dc357dd8e710f36
                // (in this commit, i added the state of this programm with this function split in 2).
                // To test it, just go to the commit 76b7b4b524748a57bd459766e1224ddcc6cef00b
                // and you will see black magic.
                // -------------------------------------------------------
                Images::Color color = tmp[y][x];

                if (x > 0) {
                    color.mergeColor(tmp[y][x - 1]);
                }
                if (y > 0) {
                    color.mergeColor(tmp[y - 1][x]);
                }
                if (x < tmp.getSize().getX() - 1) {
                    color.mergeColor(tmp[y][x + 1]);
                }
                if (y < tmp.getSize().getY() - 1) {
                    color.mergeColor(tmp[y + 1][x]);
                }
                if (x > 0 && y > 0) {
                    color.mergeColor(tmp[y - 1][x - 1]);
                }
                if (x > 0 && y < tmp.getSize().getY() - 1) {
                    color.mergeColor(tmp[y + 1][x - 1]);
                }
                if (x < tmp.getSize().getX() - 1 && y < tmp.getSize().getY() - 1) {
                    color.mergeColor(tmp[y + 1][x + 1]);
                }
                if (x < tmp.getSize().getX() - 1 && y > 0) {
                    color.mergeColor(tmp[y - 1][x + 1]);
                }
                newImage[y][x] = color;
            }
        }
        _logger.trace("HERE3");
        for (int x = 0; x < image.getSize().getX(); x++) {
            for (int y = 0; y < image.getSize().getY(); y++) {
                // -------------------------------------------------------
                // This is not in another function because i try it and
                // it caused a wild error.
                // See commit 76b7b4b524748a57bd459766e1224ddcc6cef00b
                // (in this commit add modified the test to run).
                // See commit 244e36ac46b80ec5f58fa23e2dc357dd8e710f36
                // (in this commit, i added the state of this programm with this function split in 2).
                // To test it, just go to the commit 76b7b4b524748a57bd459766e1224ddcc6cef00b
                // and you will see black magic.
                // -------------------------------------------------------
                int xx = x * 2;
                int yy = y * 2;
                Images::Color color = newImage[yy][xx];

                color.mergeColor(newImage[yy][xx + 1]);
                color.mergeColor(newImage[yy + 1][xx + 1]);
                color.mergeColor(newImage[yy + 1][xx]);
                image[y][x] = color;
            }
        }
        _logger.info("SSAAx4 Anti-Aliasing applied.");
    }
}
