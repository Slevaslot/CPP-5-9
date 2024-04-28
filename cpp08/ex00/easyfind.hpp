#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename T>

int easyfind(T type, int nb)
{
	typename T::iterator tbegin = type.begin();
	for (*tbegin; tbegin != type.end(); tbegin++)
	{
		if (*tbegin == nb)
			return (*tbegin);
	}
	throw std::out_of_range("No occurence find");
}

#endif
