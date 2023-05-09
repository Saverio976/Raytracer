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
            /**
            * @brief an exception for when the key is not found
            */
            class IParsingException: public std::exception {
                public:
                    virtual ~IParsingException() = default;
                    virtual const char *what() const throw() override = 0;
            };
            /**
            * @brief an exception for when the key is not found
            */
            class ITypeException: public std::exception {
                public:
                    virtual ~ITypeException() = default;
                    virtual const char *what() const throw() override = 0;
            };
            virtual ~ISetting() = default;
            /**
             * @brief get a precise setting of the config from key
             *
             * @param key the key
             *
             * @return true if the setting exists, false otherwise
             */
            virtual void getSetting(const std::string &key) = 0;
            /**
             * @brief access element at index
             *
             * @param index the index
             *
             * @return true if the setting exists, false otherwise
             */
            virtual void getSetting(int index) = 0;
            /**
             * @brief get the length of the current key
             * works only for lists, array, groups
             *
             * @return -1 if invalid type or size
             */
            virtual int getLength() const = 0;
            /**
             * @brief gets the full path of the current setting
             *
             * @return the path
             */
            virtual std::string getPath() const = 0;
            /**
             * @brief gets the key of the current setting
             *
             * @return the key
             */
            virtual std::string getKey() const = 0;
            /**
             * @brief gets the config of a setting
             *
             * @return the config
             */
            virtual std::shared_ptr<libconfig::Config> getConfig() const = 0;
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
            virtual std::unique_ptr<ISetting> get(const std::string &key) const = 0;
            /**
             * @brief search the setting at the given index in the childs
             *
             * @param index the index to go to
             *
             * @return a copy of the setting, moved to the index
             */
            virtual std::unique_ptr<ISetting> get(int index) const = 0;
            /**
            * @brief returns the current setting
            *
            * @return a copy of the setting at the current emplacement
            */
            virtual std::unique_ptr<ISetting> get() const = 0;
            /**
             * @brief cast operator to get the value
             *
             * @return
             */
            virtual explicit operator bool() const = 0;
            virtual explicit operator int() const = 0;
            virtual explicit operator double() const = 0;
            virtual explicit operator const char *() const = 0;
            virtual explicit operator std::string() const = 0;
    };
}

#endif /*ISETTING_HPP_*/
