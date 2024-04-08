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

int	strisdigit(char * input);
int	is_double(double n);
int	exception(std::string input);
char	which_type(std::string, char *c_strr);
int		for_char(std::string input);
int	for_digit(std::string input, char *c_strr, const char *c_str, int *ci);
void	None();

#endif
