/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.cpp
*/

#include "SceneLoader.hpp"
#include "ISetting.hpp"

namespace RayTracer::Scenes {
    SceneLoader::SceneLoader(const std::string &filePath): _filePath(filePath) {};

    void SceneLoader::subscribe(const std::string &event, std::function<void(const ISetting &)> func) {
        this->_events.emplace(event, func);
    }

    void SceneLoader::update() {
        std::filesystem::file_time_type currentTime = std::filesystem::last_write_time(_filePath);

        if (currentTime != _lastWriteTime) {
            auto it = _events.find("onChange");
            _configWrapper->readFile(_filePath.c_str());

            if (it == _events.end())
                return;
            it->second(*_configWrapper->getSetting());
        }
    }
}
