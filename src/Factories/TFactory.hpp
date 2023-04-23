/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IFactory.hpp
*/

#ifndef IFACTORY_HPP_
    #define IFACTORY_HPP_

    #include <string>
    #include <memory>
    #include <map>

class IConfig; // TODO: create an iconfig please

namespace RayTracer::Factories {
    /**
     * @brief The TFactory
     *
     * @tparam Handler the handler class type
     * @tparam Interface the interface class type
     */
    template <typename Handler, typename Interface>
    class TFactory {
        public:
            ~TFactory() = default;
            /**
             * @brief Add an `handler`
             *
             * @param name the name
             * @param handler the handler
             */
            void add(const std::string &name, std::unique_ptr<Handler> handler);
            /**
             * @brief Get an `interface`
             *
             * @param name the name
             * @param config the config
             *
             * @return the interface
             */
            std::unique_ptr<Interface> get(const std::string &name, IConfig config);
            /**
             * @brief Get the factory
             *
             * @return the factory
             */
            static TFactory<Handler, Interface> &getFactory();
            /**
             * @brief Clear all handler
             */
            void clearAll();

        protected:
            TFactory();
            static std::unique_ptr<TFactory<Handler, Interface>> _factory;
            std::map<std::string, std::unique_ptr<Handler>> _stock;
        private:
    };
}

#endif /*IFACTORY_HPP_*/
