/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityHandler.hpp
*/

#ifndef MATERIALHANDLER_HPP_
    #define MATERIALHANDLER_HPP_

    #include <memory>
    #include <string>
    #include "IMaterial.hpp"
    #include "IMaterialCreator.hpp"
    #include "ILogger.hpp"
    #include "PluginHandler.hpp"
    #include "ISetting.hpp"

namespace RayTracer::Plugins::Materials {
    /**
     * @brief The MaterialHandler
     *
     * class that represent an material handler (take a .so)
     */
    class MaterialHandler {
        public:
            /**
             * @brief MaterialHandler constructor
             *
             * @param filePath the file path
             */
            MaterialHandler(const std::string &filePath);
            /**
             * @brief Get an material (and create it with setting)
             *
             * @param setting the setting
             *
             * @return the material
             */
            RayTracer::Entities::IMaterial &get(const RayTracer::Scenes::ISetting &setting, ILogger &logger);
        private:
            PluginHandler<RayTracer::Entities::IMaterial, IMaterialCreator> _handler;
    };
}

#endif
