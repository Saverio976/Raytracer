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

class FilterFactory : public TFactory<FilterHandler, IFilter> {
	public:
		~FilterFactory() = default;
        void addFilter(const std::string &name, std::unique_ptr<FilterHandler> handler);
        IFilter getFilter(const std::string &name, IConfig config);
        static FilterFactory &getFilterFactory();

	protected:
		FilterFactory();
	private:
};

#endif /*FILTERFACTORY_HPP_*/
