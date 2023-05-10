/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SettingWrapper.hpp
*/

#ifndef RAYTRACER_SETTINGWRAPPER_HPP
    #define RAYTRACER_SETTINGWRAPPER_HPP

    #include <libconfig.h++>
    #include <memory>
    #include <exception>
    #include "ISetting.hpp"

namespace RayTracer::Scenes {
    /**
     * @brief The SettingWrapper class
     *
     * class that represent a setting in a scene configuration
     * it allows the user to navigate through the scene configuration by changing the path of the setting
     */
    class SettingWrapper: public ISetting {
        public:
            /**
            * @brief an exception for when the key is not found
            */
            class ParsingException: public ISetting::IParsingException {
                public:
                    explicit ParsingException(const std::string &key);
                    const char *what() const throw() final;
                private:
                    std::string _msg;
            };
            /**
            * @brief an exception for when the key is not found
            */
            class TypeException: public ISetting::ITypeException {
                public:
                    explicit TypeException(const std::string &key);
                    const char *what() const throw() final;
                private:
                    std::string _msg;
                };
            /**
            * @brief Creates a SettingWrapper
            *
            * @param config the config to wrap from libconfig++
            */
            explicit SettingWrapper(const std::shared_ptr<libconfig::Config> &config);
            SettingWrapper(const ISetting &src);
            ~SettingWrapper() = default;
            /**
            * @brief get a precise setting of the config from key
            *
            * @param key the key
            *
            * @return true if the setting exists, false otherwise
            */
            void getSetting(const std::string &key) final;
            /**
            * @brief access element at index
            *
            * @param index the index
            *
            * @return true if the setting exists, false otherwise
            */
            void getSetting(int index) final;
            /**
            * @brief get the length of the current key
            * works only for lists, array, groups
            *
            * @return -1 if invalid type or size
            */
            int getLength() const final;
            /**
            * @brief gets the full path of the current setting
            *
            * @return the path
            */
            std::string getPath() const final;
            /**
            * @brief gets the key of the setting
            *
            * @return the key
            */
            std::string getKey() const final;
            /**
            * @brief gets the config of a setting
            *
            * @return the config
            */
            std::shared_ptr<libconfig::Config> getConfig() const final;
            /**
            * @brief move to the given key
            *
            * @param key the key
            */
            void moveTo(const std::string &key) final;
            /**
            * @brief move to the given index
            *
            * @param index the index
            */
            void moveTo(int index) final;

            /**
            * @brief search the setting at the given key in the childs
            *
            * @param key the key to go to
            *
            * @return a copy of the setting, moved to the key
            */
            std::unique_ptr<ISetting> get(const std::string &key) const final;
            /**
            * @brief search the setting at the given index in the childs
            *
            * @param index the index to go to
            *
            * @return a copy of the setting, moved to the index
            */
            std::unique_ptr<ISetting> get(int index) const final;
            /**
            * @brief returns the current setting
            *
            * @return a copy of the setting at the current emplacement
            */
            std::unique_ptr<ISetting> get() const final;
            /**
            * @brief cast operator to get bool from setting
            *
            * @return
            */
            explicit operator bool() const final;
            explicit operator int() const final;
            explicit operator double() const final;
            explicit operator const char *() const final;
            explicit operator std::string() const final;
        private:
            libconfig::Setting *_setting;
            std::shared_ptr<libconfig::Config> _config;
    };
}

#endif //RAYTRACER_SETTINGWRAPPER_HPP
