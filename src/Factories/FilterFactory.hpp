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
    class FilterFactory : public TFactory<Plugins::Filters::FilterHandler, Filters::IFilter> {
        public:
            ~FilterFactory() = default;
            /**
             * @brief Add a filter
             *
             * @param name the name
             * @param handler the handler
             */
            void addFilter(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler);
            /**
             * @brief Get a filter
             *
             * @param name the name
             * @param config the config
             *
             * @return the filter
             */
            std::unique_ptr<Filters::IFilter> getFilter(const std::string &name, IConfig config);
            /**
             * @brief Get the filter factory instance
             *
             * @return the filter factory instance
             */
            static FilterFactory &getFilterFactory();

        protected:
            FilterFactory();
        private:
    };
}

#endif /*FILTERFACTORY_HPP_*/
