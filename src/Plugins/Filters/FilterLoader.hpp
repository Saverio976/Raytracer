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

class FilterLoader {
    public:
        FilterLoader(const std::string &directory);
        void load(TFactory<FilterHandler, IFilter> &factory);

    protected:
    private:
        std::string _directory;
};

#endif /*FILTERLOADER_HPP_*/
