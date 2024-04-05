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

int	strisdigit(char * input)
{
	size_t i = 0;
	int nbrvir = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (input[i])
	{
		if (input[i] == '.')
		{
			nbrvir++;
			i++;
		}
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	if (nbrvir > 1)
	{
		std::cout << nbrvir << std::endl;
		return (0);
	}
	return (1);
}

int	is_double(double n)
{
	int i = (int)n;
	if (n == 0)
		return (1);
	if (fmod(n,static_cast<double>(i)))
		return (0);
	return (1);
}

int	exception(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf" || input == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (input.length() < 5)
			{
				std::cout << "double: " << input << std::endl;
				std::cout << "float: " << input << "f" << std::endl;
			}
			else
			{
				std::string ok = input;
				std::cout << "double: " << input.erase(4) << std::endl;
				std::cout << "float: " << ok << std::endl;
			}
			return (1);
		}
	return (0);
}

void ScalarConverter::convert(std::string input)
{
		const char* c_str = static_cast<const char *>(input.c_str());
		char *c_strr = (char *)c_str;
		int ci = 0;
		if (exception(input))
			return ;
		if (input.length() == 1)
		{
			if (input[0] >= '0' && input[0] <= '9')
			{
				std::cout << "char: Non displayable" << std::endl;
				ci = 1;
			}
			else
			{
				std::cout << "char: " << input[0] << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				return;
			}
		}
		if (input[input.length() - 1] == 'f' && input.length() != 1)
			c_strr[input.length() - 1] = 0;
		if (strisdigit(c_strr))
		{
			double digit = strtod(c_str, NULL);
			if (ci == 0)
			{
				if (static_cast<int>(digit) < 128 && static_cast<int>(digit) >= 0)
				{
					char c = static_cast<int>(digit);
					if (c > 31 && c < 127)
						std::cout << "char: " << c << std::endl;
					else
						std::cout << "char : Non displayable" << std::endl;
					ci = 1;
				}
			}
			if (ci == 0)
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << static_cast<int>(digit) << std::endl;
			std::cout << "double: " << input;
			if (is_double(digit))
				std::cout << ".0";
			std::cout << std::endl;
			std::cout << "float: " << atof(c_str);
			if (is_double(digit))
				std::cout << ".0";
			std::cout << 'f' << std::endl;
		}
		else
		{
			if (ci == 0)
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
		}
}

