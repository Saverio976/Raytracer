/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Progress.cpp
*/

#include <iostream>
#include "ILogger.hpp"
#include "Logger.hpp"
#include "Progress.hpp"

namespace RayTracer {
    Progress::Progress(float max, float threshold, ILogger &logger):
        _logger(logger),
        _max(max),
        _step(threshold * 100),
        _current(0),
        _nextStep(_step)
    {
    }

    void Progress::add(float value)
    {
        if (_nextStep > 100) {
            return;
        }
        _current += ((value * 100.0) / _max);
        if (_current >= _nextStep) {
            _logger.info("Progress: " + std::to_string(_nextStep) + "%");
            _nextStep += _step;
        }
    }
}
