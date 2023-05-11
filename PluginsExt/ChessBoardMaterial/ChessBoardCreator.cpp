/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.cpp
*/

#include "ChessBoardCreator.hpp"
#include "ILogger.hpp"
#include "ChessBoardMaterial.hpp"

namespace RayTracer::PluginsExt::ChessBoard {
    ChessBoardCreator::~ChessBoardCreator() {
        for (ChessBoardMaterial *element : this->_elements)
            delete element;
    }

    RayTracer::Entities::IMaterial *ChessBoardCreator::create(const Scenes::ISetting &config, ILogger &logger) {
        ChessBoardMaterial *element = new ChessBoardMaterial(config);
        this->_elements.push_back(element);
        return element;
    }
}
