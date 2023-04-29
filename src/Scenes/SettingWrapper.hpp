/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SettingWrapper.hpp
*/

#ifndef RAYTRACER_SETTINGWRAPPER_HPP
#define RAYTRACER_SETTINGWRAPPER_HPP
#include <libconfig.h++>
#include <iostream>
#include <memory>
#include <exception>

namespace Raytracer::Scenes {
    /**
     * @brief The SettingWrapper class
     *
     * class that represent a setting in a scene configuration
     * it allows the user to navigate through the scene configuration by changing the path of the setting
     */
    class SettingWrapper {
        /**
         * @brief an exception for when the key is not found
         */
        class KeyNotFoundException: public std::exception {
        public:
            explicit KeyNotFoundException(const std::string &key);
            const char *what() const throw();
        private:
            std::string _msg;
        };
        /**
         * @brief an exception for invalid type
         */
        class InvalidTypeSearchIndex: public std::exception {
        public:
            explicit InvalidTypeSearchIndex(const std::string &key);
            const char *what() const throw();
        private:
            std::string _msg;
        };
    public:
        /**
         * @brief Creates a SettingWrapper
         *
         * @param config the config to wrap from libconfig++
         */
        explicit SettingWrapper(const std::shared_ptr<libconfig::Config> &config);
        SettingWrapper(SettingWrapper &src);
        ~SettingWrapper() = default;
        /**
         * @brief get a precise setting of the config from key
         *
         * @param key the key
         *
         * @return true if the setting exists, false otherwise
         */
        bool getSetting(const std::string &key);
        /**
         * @brief access element at index
         *
         * @param index the index
         *
         * @return true if the setting exists, false otherwise
         */
        bool getSetting(int index);
        /**
         * @brief get the length of the current key
         * works only for lists, array, groups
         *
         * @return -1 if invalid type or size
         */
        int getLength();
        /**
         * @brief gets the path of the current setting
         *
         * @return the path
         */
        std::string getPath();
        /**
         * @brief gets the config of a setting
         *
         * @return the config
         */
        std::shared_ptr<libconfig::Config> getConfig();
        /**
         * @brief
         *
         * @param key
         */
        void moveTo(const std::string &key);
        /**
         * @brief
         *
         * @param index
         */
        void moveTo(int index);

        /**
         * @brief search the setting at the given key in the childs
         *
         * @param key the key to go to
         *
         * @return a copy of the setting, moved to the key
         */
        SettingWrapper operator[](const std::string &key);
        /**
         * @brief search the setting at the given index in the childs
         *
         * @param index the index to go to
         *
         * @return a copy of the setting, moved to the index
         */
        SettingWrapper operator[](int index);
        /**
         * @brief cast operator to get bool from setting
         *
         * @return
         */
        explicit operator bool() const;
        explicit operator int() const;
        explicit operator double() const;
        explicit operator const char *() const;
        explicit operator std::string() const;
    private:
        libconfig::Setting *_setting;
        std::shared_ptr<libconfig::Config> _config;
    };
}

#endif //RAYTRACER_SETTINGWRAPPER_HPP