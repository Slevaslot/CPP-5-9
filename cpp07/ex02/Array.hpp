#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>
#include <iostream>
template <typename T>

class Array
{
	private :
		T *_array;
		unsigned int _size;
	public :
		Array()
		{
			_array = NULL;
			_size = 0;
		}
		Array (unsigned int n)
		{
			_array = new T[n];
			_size = n;
		}
		Array (Array &t)
		{
			_size = t._size;
			_array = new T[_size];
			unsigned int i = -1;
			while (++i < _size)
				_array[i] = t._array[i];
		}
		unsigned int size()
		{
			int i = -1;
			while(++i < _size)
				;
			return i;
		}
		Array &operator=(Array &t)
		{
			_size = t._size;
			_array = new T[_size];
			unsigned int i = -1;
			while (++i < _size)
				_array[i] = t._array[i];
			return (*this);
		}
		T &operator[](unsigned int n)
		{
				if (n <= _size)
					return _array[n];
				else
					throw std::out_of_range("-- This array is out of range! --");
		}

};

#endif
