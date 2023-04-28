/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneConfig.hpp
*/

#ifndef RAYTRACER_SCENECONFIG_HPP
    #define RAYTRACER_SCENECONFIG_HPP
    #include <libconfig.h++>
    #include <iostream>
    #include <memory>
    #include <exception>

namespace Raytracer::Scenes {
    /**
     * @brief The SceneConfig class
     *
     * class that represent a scene configuration
     */
    class SceneConfig {
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
             * @brief Creates a SceneConfig
             *
             * @param config the config to wrap from libconfig++
             */
            explicit SceneConfig(const std::shared_ptr<libconfig::Config> &config);
            ~SceneConfig() = default;
            /**
             * @brief get a precise setting of the config from key
             *
             * @param key the key
             *
             * @return true if the setting exists, false otherwise
             */
            bool getSetting(const std::string &key);
            /**
             * @brief get the length of the current key
             * works only for lists, array, groups
             *
             * @return -1 if invalid type or size
             */
            int getLength();
            /**
             * @brief get the value at given index (works for list, groups, arrays only)
             *
             * @tparam T the type of the value to get
             *
             * @param index the index of the value
             *
             * @return the value
             */
            template<typename T>
            T getSettingValue(int index) {
                try {
                    libconfig::Setting &tmpSetting = _setting->operator[](index);
                    T result = tmpSetting;

                    return (result);
                } catch (libconfig::SettingTypeException &e) {
                    throw SceneConfig::InvalidTypeSearchIndex(e.getPath());
                } catch (libconfig::SettingNotFoundException &e) {
                    throw SceneConfig::KeyNotFoundException(e.getPath());
                }
            }
            /**
             * @brief gets the value of the current setting
             *
             * @tparam T the type of value to return
             *
             * @return the value if it exists, throws a KeyNotFoundException exception otherwise
             */
            template<typename T>
            T getSettingValue() {
                T result;

                if (!_setting->exists(_setting->getPath()))
                    throw SceneConfig::KeyNotFoundException(_setting->getPath());
                result = _setting;
                return (result);
            }
            /**
             * @brief gets the value of the setting that has the given key
             *
             * @param key the path to the wanted setting
             *
             * @return the value if it exists, throws a KeyNotFoundException exception otherwise
             */
            template<typename T>
            T getSettingValue(const std::string &key) {
                T result;

                if (!getSetting(key))
                    throw SceneConfig::KeyNotFoundException(key);
                result = _setting;
                return (result);
            }
        private:
            libconfig::Setting *_setting;
            std::shared_ptr<libconfig::Config> _config;
    };
}


#endif //RAYTRACER_SCENECONFIG_HPP
