/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FilterFactory.hpp
*/

#ifndef FILTERFACTORY_HPP_
    #define FILTERFACTORY_HPP_

    #include "IFilterFactory.hpp"
#include "ILogger.hpp"
    #include "TFactory.hpp"
    #include "FilterHandler.hpp"
    #include "IFilter.hpp"

namespace RayTracer::Factories {
    /**
     * @brief The FilterFactory (singleton factory)
     */
    class FilterFactory : public IFilterFactory {
        public:
            FilterFactory(const FilterFactory &other) = delete;
            ~FilterFactory() = default;
            /**
             * @brief Add a filter
             *
             * @param name the name
             * @param handler the handler
             */
            void add(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler);
            /**
             * @brief Get a filter
             *
             * @param name the name
             * @param setting the setting
             *
             * @return the filter
             */
            Filters::IFilter &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) final;
            /**
             * @brief Clear all filters
             */
            void clearAll();
            /**
             * @brief Get the singleton
             *
             * @return the singleton
             */
            static FilterFactory &getInstance();

        protected:
            FilterFactory() = default;
            static TFactory<Plugins::Filters::FilterHandler, Filters::IFilter> &getFactory();
            static std::unique_ptr<FilterFactory> _factory;
        private:
    };
}

#endif /*FILTERFACTORY_HPP_*/
