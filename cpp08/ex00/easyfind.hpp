#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

int easyfind(T type, int nb)
{
	typename T::iterator tbegin = std::find(type.begin(), type.begin(), nb);
	while (tbegin <= type.end())
	{
		if (*tbegin == nb)
			return (*tbegin);
		++tbegin;
	}
	throw std::out_of_range("No occurence find");
	// return (0);
}

#endif
