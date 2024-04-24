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
		const char* c_str = static_cast<const char *>(input.c_str());
		char *c_strr = (char *)c_str;
		int ci = 0;
		char type;
		type = which_type(input, c_strr);
		switch(type)
		{
			case 'E':
				break ;
			case 'C':
				ci = for_char(input);
				if (ci == 1)
					for_digit(input, c_strr, c_str, &ci);
				break;
			case 'D':
				for_digit(input, c_strr, c_str, &ci);
				break;
			case 'F':
				for_digit(input, c_strr, c_str, &ci);
				break;
			case 'N':
				if (ci == 0)
					None();
				break;
		}
}

