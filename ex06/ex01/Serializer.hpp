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
		virtual ~Serializer() = 0;

		uintptr_t static serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
