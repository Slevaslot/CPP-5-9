#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	std::fstream data;
	std::string information;
	char Char;
	data.open("data.csv", std::fstream::in);
	if (data.is_open())
	{
		while(data >> Char)
			information += Char;
	}
	else {
    std::cerr << "Error opening file!" << std::endl;
  }
}

