#include "../ScalarConverter.hpp"

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
	int i = (int)n;//add static cast
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

char	which_type(std::string input, char *c_strr)
{
	if (exception(input))
		return 'E';
	if (input.length() == 1)
		return 'C';
	if (input[input.length() - 1] == 'f' && input.length() != 1)
		return 'F';
	if (strisdigit(c_strr))
		return 'D';
	else
		return 'N';

}

int		for_char(std::string input)
{
	if (input[0] >= '0' && input[0] <= '9')
	{
			 std::cout << "char: Non displayable" << std::endl;
		return (1);
	}
	else
	{
		std::cout << "char: " << input[0] << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		return (0);
	}
	return (0);
}

int	for_digit(std::string input, char *c_strr, const char *c_str, int *ci)
{
	if (input[input.length() - 1] == 'f' && input.length() != 1)
	c_strr[input.length() - 1] = 0;
	double digit = strtod(c_str, NULL);
	if (*ci == 0)
	{
		if (static_cast<int>(digit) < 128 && static_cast<int>(digit) >= 0)
		{
			char c = static_cast<int>(digit);
			if (c > 31 && c < 127)
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char : Non displayable" << std::endl;
			*ci = 1;
		}
	}
	if (*ci == 0)
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
	return (0);
}

void	None()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
}
