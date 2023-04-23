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

template <typename Handler, typename Interface>
class TFactory {
	public:
		~TFactory() = default;
        void add(const std::string &name, std::unique_ptr<Handler> handler);
        Interface get(const std::string &name, IConfig config);
        static TFactory<Handler, Interface> &getInstance();
        void clearAll();

	protected:
        TFactory();
        static TFactory<Handler, Interface> _factory;
	private:
};

#endif /*IFACTORY_HPP_*/