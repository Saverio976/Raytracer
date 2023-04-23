/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PluginHandler.hpp
*/

#ifndef PLUGINHANDLER_HPP_
    #define PLUGINHANDLER_HPP_

    #include <string>
    #include <memory>

class IConfig; // TODO: create an iconfig please

template<typename Interface, typename Creator>
class PluginHandler {
	public:
		PluginHandler(const std::string &filePath);
		~PluginHandler();
        std::unique_ptr<Interface> get(const IConfig &config);

	protected:
        Creator *_creator;
        std::string _filePath;
        void *_handler;
	private:
};

#endif /*PLUGINHANDLER_HPP_*/
