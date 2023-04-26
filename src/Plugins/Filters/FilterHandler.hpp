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

class IConfig; // TODO: create an iconfig please

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
             * @brief Get a filter (and create it with config)
             *
             * @param config the config
             *
             * @return the filter
             */
            std::unique_ptr<RayTracer::Filters::IFilter> get(const IConfig &config);

        private:
            PluginHandler<RayTracer::Filters::IFilter, IFilterCreator> _handler;
    };
}

#endif /*FILTERHANDLER_HPP_*/
