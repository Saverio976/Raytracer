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

namespace RayTracer::Plugins::Filters {
    /**
     * @brief The IFilterCreator class
     *
     * class that represent a filter creator
     */
    class IFilterCreator {
        public:
            virtual ~IFilterCreator() = default;
            /**
             * @brief Create a filter with a config
             *
             * @param config the config
             *
             * @return the filter
             */
            virtual std::unique_ptr<RayTracer::Filters::IFilter> create(const IConfig &config) = 0;

        protected:
        private:
    };
}

#endif /*IFILTERCREATOR_HPP_*/
