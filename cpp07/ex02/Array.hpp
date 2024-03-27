#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>

class Array
{
	private :
		T *_array;
		unsigned int _size;
	public :
		Array(void)
		{
			_array = NULL;
			_size = 0;
		}
		Array (unsigned int n)
		{
			_array = new T[n] = 0;
			_size = n;
		}
		Array (Array &t)
		{
			_array = new Array[t.size];
			_size = t._size;
			int i = -1;
			while (++i < _size)
				_array[i] = t._array[i];
		}

};

#endif
