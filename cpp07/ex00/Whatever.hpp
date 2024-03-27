#include <iostream>
#include <string>


template <typename T>

void swap (T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>

T min (T &a, T &b)
{
	T ret = (a < b) ? a : b;
	return ret;
}

template <typename T>

T max (T &a, T &b)
{
	T ret = (a > b) ? a : b;
	return ret;
}
