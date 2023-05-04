/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterHandler.hpp
*/

#ifndef FILTERHANDLER_HPP_
    #define FILTERHANDLER_HPP_
    #include <memory>
    #include <string>
    #include "IFilter.hpp"
    #include "PluginHandler.hpp"
    #include "IFilterCreator.hpp"
    #include "IConfig.hpp"

namespace RayTracer::Plugins::Filters {
    /**
     * @brief The FilterHandler
     *
     * class that represent a filter handler (take a .so)
     */
    class FilterHandler {
        public:
            /**
             * @brief FilterHandler constructor
             *
             * @param filePath the file path
             */
            FilterHandler(const std::string &filePath);
            /**
             * @brief Get a filter (and create it with setting)
             *
             * @param config the setting
             *
             * @return the filter
             */
            RayTracer::Filters::IFilter &get(const RayTracer::Scenes::ISetting &setting);

        private:
            PluginHandler<RayTracer::Filters::IFilter, IFilterCreator> _handler;
    };
}

#endif /*FILTERHANDLER_HPP_*/
