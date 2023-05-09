/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SpotLightEntity.hpp
*/

#ifndef SPOTLIGHTENTITY_HPP_
    #define SPOTLIGHTENTITY_HPP_

    #include "ILight.hpp"
    #include "IConfig.hpp"
    #include "ILogger.hpp"
    #include "Transform.hpp"

namespace RayTracer::PluginsExt::SpotLight {
    class SpotLightEntity : public RayTracer::Entities::ILight {
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
        SpotLightEntity(const Scenes::ISetting &config, ILogger &logger);
        ~SpotLightEntity() = default;
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
        /**
         * @brief get the power of the light
         *
         * @return the value of the power
        */
        double getPower() const final;

    protected:
    private:
        Entities::Transform::Transform _transform;
        Images::Color _color;
        ILogger &_logger;
        double _power;
        double _radius;
        double _angle;
    };
}

#endif
