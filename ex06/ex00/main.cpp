#include "ScalarConverter.hpp"

int main(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	std::string input = av[1];
	ScalarConverter::convert(input);
	return 0;
}
