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
    #include "IDisplayable.hpp"

namespace RayTracer::Scenes {
    /**
     * @brief The Displayable class
     *
     * class that represent a displayable
     */
    class Displayable : public IDisplayable {
        public:
            /**
             * @brief Get the light list (const)
             *
             * @return the light list
             */
            const std::vector<std::unique_ptr<Entities::ILight>> &getLightList() const final;
            /**
             * @brief Get the light list
             *
             * @return the light list
             */
            std::vector<std::unique_ptr<Entities::ILight>> &getLightList() final;
            /**
             * @brief Get the primitive list (const)
             *
             * @return the primitive list
             */
            const std::vector<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList() const final;
            /**
             * @brief Get the primitive list
             *
             * @return the primitive list
             */
            std::vector<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList() final;

        protected:
        private:
            std::vector<std::unique_ptr<Entities::ILight>> _lights;
            std::vector<std::unique_ptr<Entities::IPrimitive>> _primitives;
    };
}

#endif /*DISPLAYABLE_HPP_*/
