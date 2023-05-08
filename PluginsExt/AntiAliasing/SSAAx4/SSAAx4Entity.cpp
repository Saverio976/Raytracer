
/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SSAAx4Entity.hpp
*/

#include "Color.hpp"
#include "ILogger.hpp"
#include "IFilter.hpp"
#include "ISetting.hpp"
#include "Image.hpp"
#include "SSAAx4Entity.hpp"
#include "Vector2i.hpp"
#include <exception>

namespace RayTracer::PluginsExt::AntiAliasing::SSAAx4 {
    SSAAx4Entity::SSAAx4Entity(const Scenes::ISetting &config, ILogger &logger):
        _logger(logger)
    {
    }

    Images::Color SSAAx4Entity::getPixelMean(const Images::Image *image, const Entities::Transform::Vector2i &pos) const
    {
        _logger.trace("SSAAx4Entity::getPixelMean: image size: [x:" + std::to_string(image->getSize().getX()) + ",y: " + std::to_string(image->getSize().getY()) + "]");
        Images::Color color = (*image)[pos.getY()][pos.getX()];

        _logger.trace("SSAAx4Entity::getPixelMean: 1");
        if (pos.getX() > 0) {
            color.mergeColor((*image)[pos.getY()][pos.getX() - 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 2");
        if (pos.getY() > 0) {
            color.mergeColor((*image)[pos.getY() - 1][pos.getX()]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 3");
        if (pos.getX() < image->getSize().getX() - 1) {
            color.mergeColor((*image)[pos.getY()][pos.getX() + 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 4");
        if (pos.getY() < image->getSize().getY() - 1) {
            color.mergeColor((*image)[pos.getY() + 1][pos.getX()]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 5");
        if (pos.getX() > 0 && pos.getY() > 0) {
            color.mergeColor((*image)[pos.getY() - 1][pos.getX() - 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 6");
        if (pos.getX() > 0 && pos.getY() < image->getSize().getY() - 1) {
            color.mergeColor((*image)[pos.getY() + 1][pos.getX() - 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 7");
        if (pos.getX() < image->getSize().getX() - 1 && pos.getY() < image->getSize().getY() - 1) {
            color.mergeColor((*image)[pos.getY() + 1][pos.getX() + 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 8");
        if (pos.getX() < image->getSize().getX() - 1 && pos.getY() > 0) {
            color.mergeColor((*image)[pos.getY() - 1][pos.getX() + 1]);
        }
        _logger.trace("SSAAx4Entity::getPixelMean: 9");
        return color;
    }

    Images::Color SSAAx4Entity::getPixelsReduceMean(const Images::Image *image, const Entities::Transform::Vector2i &pos) const
    {
        Images::Color color = (*image)[pos.getY()][pos.getX()];

        color.mergeColor((*image)[pos.getY()][pos.getX() + 1]);
        color.mergeColor((*image)[pos.getY() + 1][pos.getX() + 1]);
        color.mergeColor((*image)[pos.getY() + 1][pos.getX()]);
        return color;
    }

    void SSAAx4Entity::apply(Images::Image &image)
    {
        _logger.info("Applying SSAAx4 Anti-Aliasing...");
        Images::Image tmp(image.getSize() * Entities::Transform::Vector2i(2, 2));
        Images::Image newImage(image.getSize() * Entities::Transform::Vector2i(2, 2));
        try {

            _logger.trace("HERE");
            for (int x = 0; x < tmp.getSize().getX(); x++) {
                for (int y = 0; y < tmp.getSize().getY(); y++) {
                    tmp[y][x] = image[y / 2][x / 2];
                }
            }
            _logger.trace("HERE2");
            for (int x = 0; x < newImage.getSize().getX() && x < tmp.getSize().getX(); x++) {
                for (int y = 0; y < newImage.getSize().getY() && y < tmp.getSize().getY(); y++) {
                    tmp[0][0];
                    _logger.trace("SSAAx4Entity::newImage:: x: " + std::to_string(x) + " y: " + std::to_string(y));
                    tmp[0][0];
                    newImage[y][x] = this->getPixelMean(&tmp, Entities::Transform::Vector2i(x, y));
                }
            }
            _logger.trace("HERE3");
            for (int x = 0; x < image.getSize().getX(); x++) {
                for (int y = 0; y < image.getSize().getY(); y++) {
                    image[y][x] = this->getPixelsReduceMean(&newImage, Entities::Transform::Vector2i(x * 2, y * 2));
                }
            }
        } catch (const std::exception &e) {
            _logger.error(e.what());
            return;
        }
        _logger.info("SSAAx4 Anti-Aliasing applied.");
    }
}
