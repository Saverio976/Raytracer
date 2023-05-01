/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.cpp
*/

#include "SceneLoader.hpp"

namespace RayTracer::Scenes {
    SceneLoader::SceneLoader(const std::string &filePath): _filePath(filePath) {
        _configWrapper = std::make_unique<ConfigWrapper>();
    };

    void SceneLoader::subscribe(const std::string &event, std::function<void(const ISetting &)> func) {
        this->_events.emplace(event, func);
    }

    void SceneLoader::update() {
        std::ifstream isOpen(_filePath.c_str());
        if (!isOpen.good())
            return;
        std::filesystem::file_time_type currentTime = std::filesystem::last_write_time(_filePath);

        if (currentTime != _lastWriteTime) {
            auto it = _events.find("onChange");
            std::cout << _filePath.empty() << std::endl;
            _configWrapper->readFile(_filePath);

            if (it == _events.end())
                return;
            it->second(*_configWrapper->getSetting());
            _lastWriteTime = currentTime;
        }
    }
}
