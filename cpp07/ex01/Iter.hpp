#include <iostream>
#include <string>

template <typename T>

void print(T x)
{
	std::cout << x << std::endl;
}

template <typename TforIter>

void Iter(TforIter *array, int size, void (*f)(TforIter))
{
	int i = 0;
	while (i < size)
		f(array[i++]);
}

