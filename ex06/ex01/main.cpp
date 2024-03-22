#include "Serializer.hpp"

int main ()
{
	Serializer s;
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";
	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "n: " << data.n << std::endl;
	std::cout << "s2: " << data.s2 << std::endl;
	std::cout << "<----------------->" << std::endl;
	uintptr_t raw = s.serialize(&data);
	std::cout << "valeur du pointeur " << raw << std::endl;
	std::cout << "<----------------->" << std::endl;
	Data *ptr = s.deserialize(raw);
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	return 0;
}
