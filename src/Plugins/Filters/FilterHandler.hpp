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

class FilterHandler : public PluginHandler<IFilter, IFilterCreator> {
    public:
        FilterHandler(const std::string &filePath);
        std::unique_ptr<IFilter> getFilter(const IConfig &config);

    protected:
    private:
};

#endif /*FILTERHANDLER_HPP_*/
