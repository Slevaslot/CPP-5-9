#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &t)
{
	*this = t;
}

Serializer &Serializer::operator=(const Serializer &t)
{
	(void)t;
	return *this;
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}


//reinterpret_cast effectue une conversion de type brut
//Cela signifie que la valeur binaire du pointeur est conservée
