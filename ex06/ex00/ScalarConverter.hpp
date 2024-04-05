#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>
class ScalarConverter
{
	private:
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &t);
		ScalarConverter &operator=(const ScalarConverter &t);
		virtual ~ScalarConverter() = 0;
		void static convert(std::string input);
};

#endif
