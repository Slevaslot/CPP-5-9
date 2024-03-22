#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &t)
{
	*this = t;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &t)
{
	(void)t;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string input)
{
	try {
		const char* c_str = input.c_str();
		char c = *c_str;
		std::cout << "char: " << c << std::endl;
	} catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}

	try {
		const char* c_str = input.c_str();
		int i = atoi(c_str);
		std::cout << "int: " << i << std::endl;
	} catch (const std::exception& e) {
		std::cout << "int: impossible" << std::endl;
	}

	try {
		const char* c_str = input.c_str();
		float f = atof(c_str);
		std::cout << "float: " << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}

	try {
		const char* c_str = input.c_str();
		double d = strtod(c_str, NULL);
		std::cout << "double: " << d << std::endl;
	} catch (const std::exception& e) {
		std::cout << "double: impossible" << std::endl;
	}
}

