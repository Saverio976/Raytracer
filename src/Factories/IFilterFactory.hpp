/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFilterFactory.hpp
*/

#ifndef IFILTERFACTORY_HPP_
    #define IFILTERFACTORY_HPP_

    #include "ISetting.hpp"
    #include "ILogger.hpp"
    #include "IFilter.hpp"

namespace RayTracer::Factories {
    /**
     * @brief The FilterFactory (singleton factory)
     */
    class IFilterFactory {
        public:
            virtual ~IFilterFactory() = default;
            /**
             * @brief Get a filter
             *
             * @param name the name
             * @param setting the setting
             *
             * @return the filter
             */
            virtual Filters::IFilter &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) = 0;
    };
}

extern "C" {
    extern RayTracer::Factories::IFilterFactory *getFilterFactoryInstance(void);
}

#endif /*FILTERFACTORY_HPP_*/
