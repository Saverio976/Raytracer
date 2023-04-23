/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.hpp
*/

#ifndef SCENELOADER_HPP_
	#define SCENELOADER_HPP_
    #include <string>
    #include <functional>
    #include <map>

class IConfig; // TODO: create an iconfig please

namespace RayTracer::Scenes {
    class SceneLoader {
    public:
        SceneLoader(const std::string &filePath);
        ~SceneLoader();
        // event == onChange
        void subscribe(const std::string &event, std::function<void(const IConfig &)>);
        void update();
    protected:
    private:
        std::map<std::string, std::function<void(const IConfig &)>> _events;
        std::string _filePath;
    };
}

#endif /*SCENELOADER_HPP_*/