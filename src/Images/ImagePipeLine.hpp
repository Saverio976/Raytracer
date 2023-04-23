/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ImagePipeLine.hpp
*/
#ifndef IMAGEPIPELINE_HPP_
    #define IMAGEPIPELINE_HPP_

    #include "Image.hpp"
    #include "Displayable.hpp"
    #include "IFilter.hpp"
    #include "Scene.hpp"

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
            ImagePipeLine(Image &image, const Scenes::Displayable &displayable, const Scenes::Scene::SceneState &state);
            /**
             * @brief Generate the image with entities displayable
             *
             * @param maxThread the max thread number to use
             * @param cluster the cluster number (1 ray represent `cluster` pixel)
             */
            void generate(std::size_t maxThread = 1, std::size_t cluster = 1);
            /**
             * @brief Apply the filter
             *
             * @param filter the filter
             */
            void apply(Filters::IFilter &filter);
            ~ImagePipeLine();

        protected:
        private:
            Image &_image;
            const Scenes::Displayable &_displayable;
            const Scenes::Scene::SceneState &_state;
    };
}

#endif /*IMAGEPIPELINE_HPP_*/
