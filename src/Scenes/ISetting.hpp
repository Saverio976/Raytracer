/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ISetting.hpp
*/

#ifndef ISETTING_HPP_
	#define ISETTING_HPP_
    #include <iostream>
    #include <memory>
    #include <libconfig.h++>

namespace RayTracer::Scenes {
    class ISetting {
        public:
            ~ISetting() = default;
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
            ISetting operator[](const std::string &key);
            /**
             * @brief search the setting at the given index in the childs
             *
             * @param index the index to go to
             *
             * @return a copy of the setting, moved to the index
             */
            ISetting operator[](int index);
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
    };
}

#endif /*ISETTING_HPP_*/
