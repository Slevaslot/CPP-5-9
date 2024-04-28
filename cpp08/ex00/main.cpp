#include "easyfind.hpp"

int main()
{
	try {
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		std::cout << "List: " << easyfind(list, 2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int> vec;
	// std::vector<int>::iterator i;
	// i = easyfind(vec, 3);
	int i = -1;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);
	try {
		i = easyfind(vec, 3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Vector: " << i << std::endl;
}
