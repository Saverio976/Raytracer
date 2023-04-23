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
    class ImagePipeLine {
        public:
            ImagePipeLine(Image &image, const Scenes::Displayable &displayable, const Scenes::Scene::SceneState &state);
            void generate(std::size_t maxThread = 1, std::size_t cluster = 1);
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
