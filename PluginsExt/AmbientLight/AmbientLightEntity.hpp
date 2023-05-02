/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLightEntity.hpp
*/

#ifndef AMBIENTLIGHTENTITY_HPP_
    #define AMBIENTLIGHTENTITY_HPP_

    #include "ILight.hpp"
    #include "IConfig.hpp"
    #include "Transform.hpp"

namespace RayTracer::PluginsExt::AmbientLight {
    class AmbientLightEntity : public RayTracer::Entities::ILight {
        public:
            AmbientLightEntity(const Scenes::ISetting &config);
            ~AmbientLightEntity() = default;
            Type getType() const final;
            Entities::Transform::ITransform &getTransform() final;
            const Entities::Transform::ITransform &getTransform() const final;
            /**
             * @brief Get the color
             *
             * @return the color
             */
            const Images::Color &getColor() const final;
            /**
             * @brief Get the color
             *
             * @param point the point of the impact
             *
             * @return the color
             */
            Images::Color getColor(const Entities::Transform::Vector3f &point, const Scenes::Displayable &displayable) const final;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            void setColor(const Images::Color &color) final;

        protected:
        private:
            Entities::Transform::Transform _transform;
            Images::Color _color;
    };
}

#endif /*AMBIENTLIGHTENTITY_HPP_*/
