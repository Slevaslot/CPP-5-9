#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	// std::vector<int>::iterator i;
	// i = easyfind(vec, 3);
	int i;
	vec.push_back(1);
	vec.push_back(3);
	try {
		i = easyfind(vec, 3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << i << std::endl;
}
