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

class ImagePipeLine {
	public:
		ImagePipeLine(Image &image, const Displayable &displayable, const Scene::SceneState &state);
        void generate(std::size_t maxThread = 1, std::size_t cluster = 1);
        void apply(IFilter &filter);
		~ImagePipeLine();

	protected:
	private:
        Image &_image;
        const Displayable &_displayable;
        const Scene::SceneState &_state;
};

#endif /*IMAGEPIPELINE_HPP_*/
