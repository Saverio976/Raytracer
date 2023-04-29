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
            virtual ~ISetting() = default;
            /**
             * @brief get a precise setting of the config from key
             *
             * @param key the key
             *
             * @return true if the setting exists, false otherwise
             */
            virtual bool getSetting(const std::string &key) = 0;
            /**
             * @brief access element at index
             *
             * @param index the index
             *
             * @return true if the setting exists, false otherwise
             */
            virtual bool getSetting(int index) = 0;
            /**
             * @brief get the length of the current key
             * works only for lists, array, groups
             *
             * @return -1 if invalid type or size
             */
            virtual int getLength() = 0;
            /**
             * @brief gets the path of the current setting
             *
             * @return the path
             */
            virtual std::string getPath() = 0;
            /**
             * @brief gets the config of a setting
             *
             * @return the config
             */
            virtual std::shared_ptr<libconfig::Config> getConfig() = 0;
            /**
             * @brief
             *
             * @param key
             */
            virtual void moveTo(const std::string &key) = 0;
            /**
             * @brief
             *
             * @param index
             */
            virtual void moveTo(int index) = 0;
            /**
             * @brief search the setting at the given key in the childs
             *
             * @param key the key to go to
             *
             * @return a copy of the setting, moved to the key
             */
            virtual ISetting &operator[](const std::string &key) = 0;
            /**
             * @brief search the setting at the given index in the childs
             *
             * @param index the index to go to
             *
             * @return a copy of the setting, moved to the index
             */
            virtual ISetting &operator[](int index) = 0;
            /**
             * @brief cast operator to get bool from setting
             *
             * @return
             */
            virtual explicit operator bool() const = 0;
            virtual explicit operator int() const = 0;
            virtual explicit operator double() const;
            virtual explicit operator const char *() const = 0;
            virtual explicit operator std::string() const = 0;
    };
}

#endif /*ISETTING_HPP_*/
