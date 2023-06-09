/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterLoader.hpp
*/
#ifndef FILTERLOADER_HPP_
    #define FILTERLOADER_HPP_

    #include <string>
    #include "TFactory.hpp"
    #include "IFilter.hpp"
    #include "FilterHandler.hpp"
    #include "PluginLoader.hpp"
    #include "FilterFactory.hpp"

namespace RayTracer::Plugins::Filters {
    /**
     * @brief The FilterLoader
     *
     * class that represent a filter loader (take a directory)
     */
    class FilterLoader : protected PluginLoader<FilterHandler, RayTracer::Filters::IFilter, Factories::FilterFactory> {
        public:
            /**
             * @brief FilterLoader constructor (doesn't load anything)
             *
             * @param directory the directory
             */
            FilterLoader(const std::string &directory);
            /**
             * @brief Load all the filters in the factory singleton
             */
            void loadFilters();

        protected:
        private:
    };
}

#endif /*FILTERLOADER_HPP_*/
