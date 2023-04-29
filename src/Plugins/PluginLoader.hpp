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

namespace RayTracer::Plugins {
    template<typename Handler, typename Interface>
    class PluginLoader {
        public:
            PluginLoader(const std::string &directory) : _directory(directory) { }

            void load(Factories::TFactory<Handler, Interface> &factory) {
                std::string currentFilePath;
                std::size_t sizeFilePath;
                std::string fileName;

                factory.clearAll();
                for (const auto &entry : std::filesystem::directory_iterator(_directory)) {
                    currentFilePath = entry.path();
                    sizeFilePath = currentFilePath.size();
                    if (currentFilePath.substr(sizeFilePath - 3, sizeFilePath) == ".so") {
                        fileName = entry.path().filename();
                        factory.add(fileName.substr(0, sizeFilePath - 3), std::make_unique<Handler>(currentFilePath));
                    }
                }
            }

        protected:
            std::string _directory;
        private:
    };
}

#endif /*PLUGINLOADER_HPP_*/
