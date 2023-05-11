
/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** BlackAndWhileFilter.hpp
*/

#include <algorithm>
#include <exception>
#include <functional>
#include <future>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "Color.hpp"
#include "ILogger.hpp"
#include "IFilter.hpp"
#include "ISetting.hpp"
#include "Image.hpp"
#include "BlackAndWhiteFilter.hpp"
#include "Vector2i.hpp"

namespace RayTracer::PluginsExt::BlackAndWhite {
    BlackAndWhiteFilter::BlackAndWhiteFilter(const Scenes::ISetting &config, ILogger &logger):
        _logger(logger),
        _method(*config.get("method"))
    {
        std::vector<std::string> availibleModes = {
            "R", "G", "B", "Max", "Min", "Average"
        };
        try {
            _maxThread = static_cast<int>(*config.get("maxThreads"));
            _maxThread = (_maxThread == -1) ? std::thread::hardware_concurrency() : _maxThread;
        } catch (const Scenes::ISetting::IParsingException &e) {
            _maxThread = std::thread::hardware_concurrency();
        } catch (const Scenes::ISetting::ITypeException &e) {
            _maxThread = std::thread::hardware_concurrency();
        }
        _maxThread = (_maxThread <= 0) ? 1 : _maxThread;
        _maxThread = std::thread::hardware_concurrency();
        _logger.info("BlackAndWhile Max threads : " + std::to_string(_maxThread));
        if (std::find(availibleModes.begin(), availibleModes.end(), _method) == availibleModes.end()) {
            std::string message = "BlackAndWhile method " + _method + " is not available (choose between:";
            for (auto it : availibleModes) {
                message += " " + it;
            }
            message += ")";
            _logger.fatal(message);
            throw std::runtime_error(message);
        }
    }

    void BlackAndWhiteFilter::waitOnePlace()
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

    void BlackAndWhiteFilter::waitAllFinisehd()
    {
        while (_futures.size() > 0) {
            for (auto it = _futures.begin() ; it != _futures.end(); it++) {
                if ((*it).wait_for(std::chrono::milliseconds(1)) == std::future_status::ready) {
                    _futures.erase(it);
                    break;
                }
            }
        }
    }

    void BlackAndWhiteFilter::apply(Images::Image &image)
    {
        _logger.info("Applying BlackAndWhile...");

        for (int x = 0; x < image.getSize().getX(); x++) {
            this->waitOnePlace();
            std::string method = _method;
            _futures.push_back(std::async(std::launch::async, [&image, x, method]() {
                for (int y = 0; y < image.getSize().getY(); y++) {
                    image[y][x] = BlackAndWhiteFilter::getColorsMean(image[y][x], method);
                }
            }));
        }
        this->waitAllFinisehd();
        _logger.info("BlackAndWhile applied.");
    }

    Images::Color BlackAndWhiteFilter::getColorsMean(const Images::Color &color, const std::string &method)
    {
        static std::map<std::string, std::function<Images::Color(const Images::Color &)>> _methods = {
            {"R", [](const Images::Color &color) {
                return Images::Color(color[Images::Color::Types::RED], color[Images::Color::Types::RED], color[Images::Color::Types::RED], color[Images::Color::Types::ALPHA]);
            }},
            {"G", [](const Images::Color &color) {
                return Images::Color(color[Images::Color::Types::GREEN], color[Images::Color::Types::GREEN], color[Images::Color::Types::GREEN], color[Images::Color::Types::ALPHA]);
            }},
            {"B", [](const Images::Color &color) {
                return Images::Color(color[Images::Color::Types::BLUE], color[Images::Color::Types::BLUE], color[Images::Color::Types::BLUE], color[Images::Color::Types::ALPHA]);
            }},
            {"Max", [](const Images::Color &color) {
                double max = std::max(std::max(color[Images::Color::Types::RED], color[Images::Color::Types::GREEN]), color[Images::Color::Types::BLUE]);
                return Images::Color(max, max, max, color[Images::Color::Types::ALPHA]);
            }},
            {"Min", [](const Images::Color &color) {
                double min = std::min(std::min(color[Images::Color::Types::RED], color[Images::Color::Types::GREEN]), color[Images::Color::Types::BLUE]);
                return Images::Color(min, min, min, color[Images::Color::Types::ALPHA]);
            }},
            {"Average", [](const Images::Color &color) {
                double sum = color[Images::Color::Types::RED] + color[Images::Color::Types::GREEN] + color[Images::Color::Types::BLUE];
                return Images::Color(sum / 3, sum / 3, sum / 3, color[Images::Color::Types::ALPHA]);
            }}
        };
        return _methods[method](color);
    }
}
