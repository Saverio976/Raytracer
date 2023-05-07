/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IDisplayable.hpp
*/

#ifndef IDISPLAYABLE_HPP_
    #define IDISPLAYABLE_HPP_

    #include <memory>
    #include <vector>

namespace RayTracer::Entities {
    class IPrimitive;
    class ILight;
}

namespace RayTracer::Scenes {
    /**
     * @brief The IDisplayable interface
     *
     * interface that represent a displayable
     */
    class IDisplayable {
        public:
            /**
            * @brief an exception for when the key is not found
            */
            class IDisplayableException: public std::exception {
                public:
                    virtual ~IDisplayableException() = default;
                    virtual const char *what() const throw() override = 0;
            };
            /**
             * @brief Get the light list (const)
             *
             * @return the light list
             */
            virtual const std::vector<std::reference_wrapper<Entities::ILight>> &getLightList() const = 0;
            /**
             * @brief Get the light list
             *
             * @return the light list
             */
            virtual std::vector<std::reference_wrapper<Entities::ILight>> &getLightList() = 0;
            /**
             * @brief Get the primitive list (const)
             *
             * @return the primitive list
             */
            virtual const std::vector<std::reference_wrapper<Entities::IPrimitive>> &getPrimitiveList() const = 0;
            /**
             * @brief Get the primitive list
             *
             * @return the primitive list
             */
            virtual std::vector<std::reference_wrapper<Entities::IPrimitive>> &getPrimitiveList() = 0;
            /**
             * @brief Get the ambient light
             *
             * @return the ambient light
             */
            virtual const Entities::ILight &getAmbientLight() const = 0;
            /**
             * @brief Get the ambient light
             *
             * @return the ambient light
             */
            virtual Entities::ILight &getAmbientLight() = 0;
    };
}

#endif /*DISPLAYABLE_HPP_*/
