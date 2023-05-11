/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneCreator.hpp
*/

#ifndef CHESSBOARDCREATOR_HPP_
    #define CHESSBOARDCREATOR_HPP_

    #include <vector>
    #include <memory>
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "ChessBoardMaterial.hpp"

namespace RayTracer::PluginsExt::ChessBoard {
    class ChessBoardCreator : public RayTracer::Plugins::Materials::IMaterialCreator {
    public:
        ~ChessBoardCreator();
        RayTracer::Entities::IMaterial *create(const Scenes::ISetting &config, ILogger &logger) final;
    protected:
    private:
        std::vector<ChessBoardMaterial *> _elements;
    };
}

#endif
