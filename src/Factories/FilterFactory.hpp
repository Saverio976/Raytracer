/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterFactory.hpp
*/
#ifndef FILTERFACTORY_HPP_
    #define FILTERFACTORY_HPP_

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
             * @param config the config
             *
             * @return the filter
             */
            static std::unique_ptr<Filters::IFilter> get(const std::string &name, const IConfig &config);
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
