/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Parameters.hpp
*/
#ifndef PARAMETERS_HPP_
    #define PARAMETERS_HPP_

    #include <memory>
    #include <map>
    #include <string>

namespace RayTracer {
    /**
     * @brief The Parameters class singleton
     *
     * (like a global config :eyes:)
     */
    class Parameters {
        public:
            ~Parameters() = default;
            Parameters(const Parameters &other) = delete;
            /**
             * @brief Get the singleton instance
             *
             * @return the parameters
             */
            static Parameters &getInstance();
            /**
             * @brief Get config key value as int
             *
             * @param key the key
             *
             * @return the int
             */
            const int getInt(const std::string &key) const;
            /**
             * @brief Get config key value as float
             *
             * @param key the key
             *
             * @return the float
             */
            const float getFloat(const std::string &key) const;
            /**
             * @brief Get config key value as string
             *
             * @param key the key
             *
             * @return the string
             */
            const std::string getString(const std::string &key) const;
            /**
             * @brief Set config key value as int
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, int value);
            /**
             * @brief Set config key value as float
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, float value);
            /**
             * @brief Set config key value as string
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, std::string value);

        protected:
            Parameters();
            static std::unique_ptr<Parameters> _parameters;
            std::map<std::string, int> _valuesInt;
            std::map<std::string, float> _valuesFloat;
            std::map<std::string, std::string> _valuesString;
        private:
    };
}

#endif /*PARAMETERS_HPP_*/
