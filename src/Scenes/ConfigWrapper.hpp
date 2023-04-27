/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigWrapper.hpp
*/

#ifndef RAYTRACER_CONFIGWRAPPER_HPP
    #define RAYTRACER_CONFIGWRAPPER_HPP
    #include <iostream>
    #include <libconfig.h++>
    #include <memory>
    #include <exception>

namespace Raytracer::Scenes {
    class ConfigWrapper {
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
                 * @brief get the setting of a precise index
                 *
                 * works only for lists, groups or arrays
                 *
                 * @param index the index (starts at 0)
                 *
                 * @return true if the setting exists, false otherwise
                 */
                bool getSetting(int index);
                /**
                 * @brief gets the value of the current setting
                 *
                 * @tparam T the type of value to return
                 *
                 * @return the value if it exists, throws an exception otherwise
                 */
                template<typename T>
                T getSettingValue();
                /**
                 * @brief gets the value of the setting that has the given key
                 *
                 * @param key the path to the wanted setting
                 *
                 * @return the value if it exists, throws an exception otherwise
                 */
                template<typename T>
                T getSettingValue(const std::string &key);
            private:
                libconfig::Setting *_setting;
                std::shared_ptr<libconfig::Config> _config;
        };
        public:
            ConfigWrapper() = default;
            ~ConfigWrapper() = default;
            /**
             * @brief read and parse the file at given path
             *
             * @param path the path to the file
             *
             * @return true if parsing worked, false otherwise
             */
            bool readFile(const std::string &path);
            /**
             * @brief writes the current config in a file at the given path
             *
             * @param path the path to the file
             *
             * @return true if writing worked, false otherwise
             */
            bool writeFile(const std::string &path);
            /**
             * @brief returns the current SceneConfig
             *
             * @return the current SceneConfig
             */
            std::shared_ptr<SceneConfig> getScene();
        private:
            std::shared_ptr<libconfig::Config> _config;
            std::shared_ptr<SceneConfig> _scene;
    };
}

#endif //RAYTRACER_CONFIGWRAPPER_HPP
