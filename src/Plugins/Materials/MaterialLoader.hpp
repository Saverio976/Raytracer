/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityLoader.hpp
*/

#ifndef MATERIALLOADER_HPP_
    #define MATERIALLOADER_HPP_

    #include <string>
    #include "TFactory.hpp"
    #include "IMaterial.hpp"
    #include "PluginLoader.hpp"
    #include "MaterialHandler.hpp"
    #include "MaterialFactory.hpp"

namespace RayTracer::Plugins::Materials {
    /**
     * @brief The EntityLoader
     *
     * class that represent an entity loader (take a directory and create EntityHandler)
     */
    class MaterialLoader : protected PluginLoader<MaterialHandler, RayTracer::Entities::IMaterial, Factories::MaterialFactory> {
    public:
        /**
        * @brief EntityLoader constructor (doesn't load anything)
        *
        * @param directory the directory
        */
        MaterialLoader(const std::string &directory);
        /**
        * @brief Load all the entities in the factory singleton
        */
        void loadMaterials();

    protected:
    private:
        std::string _directory;
    };
}

#endif /*ENTITYLOADER_HPP_*/
