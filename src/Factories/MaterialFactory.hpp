/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityFactory.hpp
*/

#ifndef MATERIALFACTORY_HPP_
    #define MATERIALFACTORY_HPP_

    #include "IMaterialFactory.hpp"
    #include "ILogger.hpp"
    #include "TFactory.hpp"
    #include "MaterialHandler.hpp"
    #include "IMaterial.hpp"

namespace RayTracer::Factories {
    /**
     * @brief The MaterialFactory (singleton factory)
     */
    class MaterialFactory : public IMaterialFactory {
        public:
            MaterialFactory(const MaterialFactory &other) = delete;
            ~MaterialFactory() = default;
            /**
             * @brief Add an material
             *
             * @param name the name
             * @param handler the handler
             */
            void add(const std::string &name, std::unique_ptr<Plugins::Materials::MaterialHandler> handler);
            /**
             * @brief Get an material
             *
             * @param name the name
             * @param setting the setting (to create the entity)
             *
             * @return the material
             */
            Entities::IMaterial &get(const std::string &name, const Scenes::ISetting &setting, ILogger &logger) final;
            /**
             * @brief Clear all handlers
             */
            void clearAll();
            /**
             * @brief Get the singleton
             *
             * @return the singleton
             */
            static MaterialFactory &getInstance();

        protected:
            MaterialFactory() = default;
            static TFactory<Plugins::Materials::MaterialHandler, Entities::IMaterial> &getFactory();
            static std::unique_ptr<MaterialFactory> _factory;
        private:
    };
}

#endif
