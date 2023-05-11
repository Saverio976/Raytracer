/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** RayIterator.hpp
*/

#ifndef IRAYITERATOR_HPP_
    #define IRAYITERATOR_HPP_

    #include <algorithm>
    #include <iterator>
#include <memory>
    #include <string>
    #include "Ray.hpp"

namespace RayTracer::Images {
    /**
     * @brief The RayIterator class
     *
     * class that represent an iterator of a ray
     */
    class IRayIterator {
        public:
            class IIterator {
                public:
                    using iterator_category = std::forward_iterator_tag;
                    using difference_type   = Ray;
                    using value_type        = Ray;
                    using pointer           = Ray *;
                    using reference         = Ray &;

                    virtual ~IIterator() = default;
                    /**
                    * @brief create the next RayIterator and modify current instance
                    *
                    * @return the current instance
                    */
                    virtual IIterator &operator++() = 0;
                    /**
                    * @brief Get the ray of the current RayIterator
                    *
                    * @return the ray
                    */
                    virtual Ray &operator*() = 0;
                    /**
                    * @brief Compare two RayIterator
                    *
                    * @param other the other
                    *
                    * @return true if equal
                    */
                    virtual bool operator==(const IRayIterator::IIterator &other) const = 0;
                    /**
                    * @brief Compare two RayIterator
                    *
                    * @param other the other
                    *
                    * @return true if not equal
                    */
                    virtual bool operator!=(const IRayIterator::IIterator &other) const = 0;
                    /**
                     * @brief toString
                     *
                     * @return the string
                     */
                    virtual std::string toString() const = 0;
            };
            virtual ~IRayIterator() = default;
            /**
             * @brief Get the begin
             *
             * @return the begin
             */
            virtual std::unique_ptr<IRayIterator::IIterator> begin() const = 0;
            /**
             * @brief Get the end (out of range)
             *
             * @return the end
             */
            virtual std::unique_ptr<IRayIterator::IIterator> end() const = 0;
    };
}

#endif
