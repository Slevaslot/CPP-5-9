#include "Span.hpp"

Span::Span() : _n(), _max(0)
{

}

Span::Span(unsigned int n) : _n(), _max(n)
{

}

Span::Span(Span const &other) : _n(other._n), _max(other._max)
{

}

Span &Span::operator=(Span const &other)
{
	_n = other._n;
	_max = other._max;
	return *this;
}

// void Span::addNumber()
// {

// 	int number;
// 	srand(static_cast<unsigned int>(std::time(0)));
// 	number = rand() % 100;
// 	std::cout << number << std::endl;
// 	for (unsigned int i = 0; i < _max; i++)
// 	{
// 		if (_n[i] == 0)
// 		{
// 			if (i < _max)
// 			{
// 				_n[i] = number;
// 				return ;
// 			}
// 			else
// 				throw std::out_of_range("Array is full");
// 		}
// 	}
// 	throw std::out_of_range("Array is full");
// }

void Span::addNumber()
{
	unsigned int number;
	srand(static_cast<unsigned int>(std::time(0)));
	number = rand() % 100;
	if (_max == 0 || _n.size() == _max)
		throw std::length_error ("error : number reach max of the array");
	_n.push_back(number);

}

void Span::addNumber(int n)
{
	if (_max == 0 || _n.size() == _max)
		throw std::length_error ("error : number reach max of the array");
	_n.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int i = 0;
	if (_max == 0 || _n.size() == _max || end < begin)
		throw std::length_error ("error : number reach max of the array");
	while (begin++ < end)
		_n.push_back(++i);
}

void Span::shortestSpan()
{
	int min = _n.front();
	std::vector<int>::iterator it;
	for (it = _n.begin(); it != _n.end(); ++it)
	{
		if (*it < min)
			min = *it;
	}
	std::cout << "Shortest span : "<< min << std::endl;
}

void Span::longestSpan()
{
	int max = _n.front();
	std::vector<int>::iterator it;
	for (it = _n.begin(); it != _n.end(); ++it)
	{
		if (*it > max)
			max = *it;
	}
	std::cout << "Longest span :" << max << std::endl;
}
