/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Displayable.hpp
*/

#ifndef DISPLAYABLE_HPP_
    #define DISPLAYABLE_HPP_

    #include <list>
    #include <memory>
    #include <vector>

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
    class Displayable {
        public:
            /**
             * @brief Get the light list (const)
             *
             * @return the light list
             */
            const std::vector<std::unique_ptr<Entities::ILight>> &getLightList() const;
            /**
             * @brief Get the light list
             *
             * @return the light list
             */
            std::vector<std::unique_ptr<Entities::ILight>> &getLightList();
            /**
             * @brief Get the primitive list (const)
             *
             * @return the primitive list
             */
            const std::vector<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList() const;
            /**
             * @brief Get the primitive list
             *
             * @return the primitive list
             */
            std::vector<std::unique_ptr<Entities::IPrimitive>> &getPrimitiveList();

        protected:
        private:
            std::vector<std::unique_ptr<Entities::ILight>> _lights;
            std::vector<std::unique_ptr<Entities::IPrimitive>> _primitives;
    };
}

#endif /*DISPLAYABLE_HPP_*/
