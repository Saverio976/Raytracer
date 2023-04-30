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
    #include <dlfcn.h>
    #include "ISetting.hpp"

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
            PluginHandler(const std::string &filePath) {
                this->_handler = dlopen(filePath.c_str(), RTLD_LAZY);
                if (!this->_handler)
                    throw std::runtime_error("Couldn't open in PluginHandler: " + std::string(dlerror()));
                _creator = this->getResult<Creator *>("getCreator");
                if (!_creator)
                    throw std::runtime_error("Creator couldn't be created in PluginHandler");
            }

            ~PluginHandler() {
                this->getResult<void>("deleteCreator", this->_creator);
                dlclose(this->_handler);
            }

            /**
             * @brief Get an interface (and create it with setting)
             *
             * @param setting the setting
             *
             * @return the interface
             */
            Interface *get(const RayTracer::Scenes::ISetting &setting) const {
                return this->_creator->create(setting);
            }

        protected:
            /**
             * @brief Call function inside the handler
             *
             * @param name the name of the function
             * @param __args arguments of the function
             *
             * @return the result of the function called
             */
            template<typename T, typename... Args>
            T getResult(const std::string &name, Args&&... __args) {
                void *sym = dlsym(this->_handler, name.c_str());

                if (!sym)
                    throw std::runtime_error("Error on open with dlsym in PluginHandler: " + std::string(dlerror()));
                T (*function)(...) = reinterpret_cast<T(*)(...)>(sym);
                return function(__args...);
            }
            Creator *_creator;
            std::string _filePath;
            void *_handler;
        private:
    };
}

#endif /*PLUGINHANDLER_HPP_*/
