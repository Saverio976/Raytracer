/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.cpp
*/

#include "SceneLoader.hpp"
#include "ILogger.hpp"
#include "Logger.hpp"

namespace RayTracer::Scenes {
    SceneLoader::SceneLoader(const std::string &filePath, ILogger &logger):
        _filePath(filePath),
        _logger(logger)
    {
        _configWrapper = std::make_unique<ConfigWrapper>();
        _entityLoader = std::make_unique<Plugins::Entities::EntityLoader>("./EntitiesPlugins"); // TODO: use parameters path
        _filterLoader = std::make_unique<Plugins::Filters::FilterLoader>("./FiltersPlugins"); // TODO: use parameters path
        _materialLoader = std::make_unique<Plugins::Materials::MaterialLoader>("./MaterialsPlugins"); // TODO: use parameters path
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
            _configWrapper->readFile(_filePath);

            if (it == _events.end())
                return;
            _logger.info("Scene config file changed, reloading...");
            this->_entityLoader->loadEntities();
            this->_filterLoader->loadFilters();
            this->_materialLoader->loadMaterials();
            it->second(*_configWrapper->getSetting());
            _lastWriteTime = currentTime;
        }
    }
}
