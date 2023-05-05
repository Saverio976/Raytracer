/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterFactory.hpp
*/
#ifndef FILTERFACTORY_HPP_
    #define FILTERFACTORY_HPP_
    #include "ILogger.hpp"
#include "TFactory.hpp"
    #include "FilterHandler.hpp"
    #include "IFilter.hpp"

namespace RayTracer::Factories {
    /**
     * @brief The FilterFactory (singleton factory)
     */
    class FilterFactory {
        public:
            ~FilterFactory() = default;
            /**
             * @brief Add a filter
             *
             * @param name the name
             * @param handler the handler
             */
            static void add(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler);
            /**
             * @brief Get a filter
             *
             * @param name the name
             * @param setting the setting
             *
             * @return the filter
             */
            static Filters::IFilter *get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger);
            /**
             * @brief Clear all filters
             */
            static void clearAll();

        protected:
            static TFactory<Plugins::Filters::FilterHandler, Filters::IFilter> &getFactory();
        private:
    };
}

#endif /*FILTERFACTORY_HPP_*/
