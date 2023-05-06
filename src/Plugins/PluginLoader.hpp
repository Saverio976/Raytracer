/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PluginLoader.hpp
*/
#ifndef PLUGINLOADER_HPP_
    #define PLUGINLOADER_HPP_
    #include <string>
    #include "TFactory.hpp"
    #include <filesystem>
    #include <memory>

namespace RayTracer::Plugins {
    template<typename Handler, typename Interface, typename Factory>
    class PluginLoader {
        public:
            PluginLoader(const std::string &directory) :
                _directory(directory) { }

            void load() {
                std::string currentFilePath;
                std::size_t sizeFilePath;
                std::string fileName;

                Factory::getInstance().clearAll();
                for (const auto &entry : std::filesystem::directory_iterator(_directory)) {
                    currentFilePath = entry.path();
                    sizeFilePath = currentFilePath.size();
                    if (currentFilePath.substr(sizeFilePath - 3, sizeFilePath) == ".so") {
                        fileName = entry.path().filename();
                        Factory::getInstance().add(fileName.substr(0, fileName.size() - 3), std::make_unique<Handler>(currentFilePath));
                    }
                }
            }

        protected:
            std::string _directory;
        private:
    };
}

#endif /*PLUGINLOADER_HPP_*/
