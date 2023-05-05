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
            /**
             * @brief Construct a new AmbientLight
             *
             * transform: {
             *      position: {x= 0; y= 0; z= 0};
             *      scale: {x= 1; y= 1; z= 1};
             *      rotation: {x= 0; y= 0; z= 0}
             * };
             * color = {r= 1; g= 1; b= 1};
             *
             * @param config the config
             */
            AmbientLightEntity(const Scenes::ISetting &config);
            ~AmbientLightEntity() = default;
            /**
             * @brief Get the type (ILight)
             *
             * @return the type
             */
            Type getType() const final;
            /**
             * @brief Get the transform
             *
             * @return the transform
             */
            Entities::Transform::ITransform &getTransform() final;
            /**
             * @brief Get the transform (const)
             *
             * @return the transform
             */
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
            Images::Color getColor(const Entities::Transform::Vector3f &point, const Scenes::IDisplayable &displayable) const final;
            /**
             * @brief Set the color
             *
             * @param color the color
             */
            void setColor(const Images::Color &color) final;
            /**
             * @brief Check if the light is ambient
             *
             * @return true if the light is ambient
             */
            bool isAmbient() const final;

        protected:
        private:
            Entities::Transform::Transform _transform;
            Images::Color _color;
    };
}

#endif /*AMBIENTLIGHTENTITY_HPP_*/
