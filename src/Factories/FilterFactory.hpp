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
    class FilterFactory : public TFactory<Plugins::Filters::FilterHandler, Filters::IFilter> {
        public:
            ~FilterFactory() = default;
            void addFilter(const std::string &name, std::unique_ptr<Plugins::Filters::FilterHandler> handler);
            Filters::IFilter getFilter(const std::string &name, IConfig config);
            static FilterFactory &getFilterFactory();

        protected:
            FilterFactory();
        private:
    };
}

#endif /*FILTERFACTORY_HPP_*/
