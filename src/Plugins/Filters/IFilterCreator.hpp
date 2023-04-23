/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFilterCreator.hpp
*/

#ifndef IFILTERCREATOR_HPP_
    #define IFILTERCREATOR_HPP_

    #include <memory>
    #include "IFilter.hpp"

class IConfig; // TODO: create an iconfig please

class IFilterCreator {
    public:
        virtual ~IFilterCreator() = default;
        virtual std::unique_ptr<IFilter> create(const IConfig &config) = 0;

    protected:
    private:
};

#endif /*IFILTERCREATOR_HPP_*/
