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
    template <typename Handler, typename Interface>
    class TFactory {
        public:
            ~TFactory() = default;
            void add(const std::string &name, std::unique_ptr<Handler> handler);
            Interface get(const std::string &name, IConfig config);
            static TFactory<Handler, Interface> &getFactory();
            void clearAll();

        protected:
            TFactory();
            static std::unique_ptr<TFactory<Handler, Interface>> _factory;
            std::map<std::string, std::unique_ptr<Handler>> _stock;
        private:
    };
}

#endif /*IFACTORY_HPP_*/
