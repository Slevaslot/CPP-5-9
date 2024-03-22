#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"
class Serializer
{
	private:
	public:
		Serializer();
		Serializer(const Serializer &t);
		Serializer &operator=(const Serializer &t);
		virtual ~Serializer();

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif
