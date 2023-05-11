/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneLoader.cpp
*/

#include <filesystem>
#include <fstream>
#include "Parameters.hpp"
#include "SceneLoader.hpp"
#include "ILogger.hpp"
#include "Logger.hpp"

namespace RayTracer::Scenes {
    SceneLoader::SceneLoader(const std::string &filePath, ILogger &logger):
        _filePath(filePath),
        _logger(logger)
    {
        SceneLoader::checkGoodFile(filePath);
        _configWrapper = std::make_unique<ConfigWrapper>(_logger);
        _entityLoader = std::make_unique<Plugins::Entities::EntityLoader>(Parameters::getInstance().getString("EntitiesSO"));
        _filterLoader = std::make_unique<Plugins::Filters::FilterLoader>(Parameters::getInstance().getString("FiltersSO"));
        _materialLoader = std::make_unique<Plugins::Materials::MaterialLoader>(Parameters::getInstance().getString("MaterialsSO"));
    };

    void SceneLoader::subscribe(const std::string &event, std::function<void(const ISetting &)> func) {
        this->_events.emplace(event, func);
    }

    void SceneLoader::update() {
        SceneLoader::checkGoodFile(_filePath);
        std::filesystem::file_time_type currentTime = std::filesystem::last_write_time(_filePath);

        if (currentTime != _lastWriteTime) {
            _logger.info("Scene config file changed, reloading...");
            auto it = _events.find("onChange");
            _configWrapper->readFile(_filePath);

            if (it == _events.end())
                return;
            auto cancelit = _events.find("onBeforeChange");
            if (cancelit != _events.end()) {
                _logger.info("canceling previous rendering...");
                cancelit->second(*_configWrapper->getSetting());
            }
            _logger.info("Reloading plugins...");
            this->_entityLoader->loadEntities();
            this->_filterLoader->loadFilters();
            _logger.debug("Relaunching the rendering...");
            this->_materialLoader->loadMaterials();
            it->second(*_configWrapper->getSetting());
            _lastWriteTime = currentTime;
        }
    }

    void SceneLoader::checkGoodFile(const std::string &filePath)
    {
        if (!filePath.ends_with(".yaax")) {
            throw BadFileError("FilePath '" + filePath + "' does not ends with '.yaax'");
        }
        if (!std::filesystem::is_regular_file(filePath)) {
            throw BadFileError("FilePath '" + filePath + "' is not a regular file");
        }
        std::ifstream isOpen(filePath);
        if (!isOpen.good()) {
            throw BadFileError("FilePath '" + filePath + "' can't be opened");
        }
    }

    // -----------------------------------------------------------------------
    // SceneLoader::BadFileError

    SceneLoader::BadFileError::BadFileError(const std::string &error):
        _error(error)
    {
    }

    const char *SceneLoader::BadFileError::what() const throw()
    {
        return _error.c_str();
    }
}
