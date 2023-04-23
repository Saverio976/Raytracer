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

class Parameters {
	public:
		~Parameters() = default;
        static Parameters &getInstance();
        const int getInt(const std::string &key) const;
        const float getFloat(const std::string &key) const;
        const std::string getString(const std::string &key) const;
        void set(const std::string &key, int value);
        void set(const std::string &key, float value);
        void set(const std::string &key, std::string value);

	protected:
		Parameters();
        static std::unique_ptr<Parameters> _parameters;
        std::map<std::string, int> _valuesInt;
        std::map<std::string, float> _valuesFloat;
        std::map<std::string, std::string> _valuesString;
	private:
};

#endif /*PARAMETERS_HPP_*/