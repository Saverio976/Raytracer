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
             * @brief Parse the command line arguments
             *
             * @param argc the number of arguments
             * @param argv the arguments
             */
            void parseCmdArgs(int argc, char **argv);
            /**
             * @brief Get config key value as int
             *
             * @param key the key
             *
             * @return the int
             */
            const int getInt(const std::string &key) const;
            /**
             * @brief Get config key value as double
             *
             * @param key the key
             *
             * @return the double
             */
            const double getdouble(const std::string &key) const;
            /**
             * @brief Get config key value as string
             *
             * @param key the key
             *
             * @return the string
             */
            const std::string &getString(const std::string &key) const;
            /**
             * @brief Set config key value as int
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, int value);
            /**
             * @brief Set config key value as double
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, double value);
            /**
             * @brief Set config key value as string
             *
             * @param key the key
             * @param value the value
             */
            void set(const std::string &key, const std::string &value);

        protected:
            Parameters();
            static std::unique_ptr<Parameters> _parameters;
            void parseCmdArg(const std::string &key, const std::string &value);
            std::map<std::string, int> _valuesInt;
            std::map<std::string, double> _valuesdouble;
            std::map<std::string, std::string> _valuesString;
        private:
    };
}

#endif /*PARAMETERS_HPP_*/
