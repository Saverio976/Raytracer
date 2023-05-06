/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Displayable.hpp
*/

#ifndef DISPLAYABLE_HPP_
    #define DISPLAYABLE_HPP_

    #include <memory>
    #include <vector>
    #include <functional>
    #include "IDisplayable.hpp"

namespace RayTracer::Entities {
    class IPrimitive;
    class ILight;
}

namespace RayTracer::Scenes {
    /**
     * @brief The Displayable class
     *
     * class that represent a displayable
     */
    class Displayable : public IDisplayable {
        public:
            /**
            * @brief an exception for when the key is not found
            */
            class DisplayableException: public IDisplayable::IDisplayableException {
                public:
                    explicit DisplayableException(const std::string &key);
                    const char *what() const throw() final;
                private:
                    std::string _msg;
            };
            /**
             * @brief Get the light list (const)
             *
             * @return the light list
             */
            const std::vector<std::reference_wrapper<Entities::ILight>> &getLightList() const final;
            /**
             * @brief Get the light list
             *
             * @return the light list
             */
            std::vector<std::reference_wrapper<Entities::ILight>> &getLightList() final;
            /**
             * @brief Get the primitive list (const)
             *
             * @return the primitive list
             */
            const std::vector<std::reference_wrapper<Entities::IPrimitive>> &getPrimitiveList() const final;
            /**
             * @brief Get the primitive list
             *
             * @return the primitive list
             */
            std::vector<std::reference_wrapper<Entities::IPrimitive>> &getPrimitiveList() final;
            /**
             * @brief Get the ambient light
             *
             * @return the ambient light
             */
            const Entities::ILight &getAmbientLight() const;
            /**
             * @brief Get the ambient light
             *
             * @return the ambient light
             */
            Entities::ILight &getAmbientLight();

        protected:
        private:
            std::vector<std::reference_wrapper<Entities::ILight>> _lights;
            std::vector<std::reference_wrapper<Entities::IPrimitive>> _primitives;
    };
}

#endif /*DISPLAYABLE_HPP_*/
