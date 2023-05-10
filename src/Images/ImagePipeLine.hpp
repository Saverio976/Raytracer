/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ImagePipeLine.hpp
*/
#ifndef IMAGEPIPELINE_HPP_
    #define IMAGEPIPELINE_HPP_

    #include "ILogger.hpp"
    #include "Image.hpp"
    #include "IDisplayable.hpp"
    #include "IFilter.hpp"
    #include "ISceneState.hpp"
    #include "IRayIterator.hpp"

namespace RayTracer::Images {
    /**
     * @brief The ImagePipeLine class
     *
     * class that represent pipeline modification on an image
     */
    class ImagePipeLine {
        public:
            /**
             * @brief ImagePipeLine constructor
             *
             * @param image the image to modify
             * @param displayable the displayable entities to render
             * @param state the state (if cancel needed)
             */
            ImagePipeLine(Image &image, const Scenes::IDisplayable &displayable, const Scenes::ISceneState &state, const IRayIterator &rayIterrator);
            /**
             * @brief Generate the image with entities displayable
             *
             * @param maxThread the max thread number to use
             * @param cluster the cluster number (1 ray represent `cluster` pixel)
             */
            void generate(ILogger &logger, std::size_t maxThread = 1, std::size_t cluster = 1);
            /**
             * @brief Apply the filter
             *
             * @param filter the filter
             */
            void apply(Filters::IFilter &filter);
            ~ImagePipeLine() = default;

        protected:
        private:
            Image &_image;
            const Scenes::IDisplayable &_displayable;
            const Scenes::ISceneState &_state;
            const IRayIterator &_rayIterrator;
    };
}

#endif /*IMAGEPIPELINE_HPP_*/
