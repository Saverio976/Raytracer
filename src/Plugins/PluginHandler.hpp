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

namespace RayTracer::Plugins {
    /**
     * @brief The PluginHandler class
     *
     * @tparam Interface the interface type of the value to get
     * @tparam Creator the creator type to create the interface
     */
    template<typename Interface, typename Creator>
    class PluginHandler {
        public:
            /**
             * @brief PluginHandler constructor (take a .so)
             *
             * @param filePath the file path
             */
            PluginHandler(const std::string &filePath);

            ~PluginHandler();

            /**
             * @brief Get an interface (and create it with config)
             *
             * @param config the config
             *
             * @return the interface
             */
            std::unique_ptr<Interface> get(const IConfig &config);

        protected:
            Creator *_creator;
            std::string _filePath;
            void *_handler;
        private:
    };
}

#endif /*PLUGINHANDLER_HPP_*/
