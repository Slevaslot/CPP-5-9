#include "Iter.hpp"

int main ()
{
	int		intArray[5] = {1, 2, 3, 4, 5};
	std::string	stringArray[5] = {"a1", "b2", "c3", "d4", "e5"};
	Iter(intArray, 5, print);
	Iter(stringArray, 5, print);
	return 0;
}
