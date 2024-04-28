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
	if (_n.capacity() < 2)
		throw std::length_error ("error : not enough number!");
	int	min = 2147483647;
	int	i = 0;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	for (it = _n.begin(); it != _n.end(); it++)
	{
		it1 = it + 1;
		if (*it < *it1)
		{
			for((void)it; *it + i < *it1; i++)
				;
			if (min > i)
				min = i;
			i = 0;
		}
		else if (*it > *it1)
		{
			for((void)it; *it - i > *it1; i++)
				;
			if (min > i)
				min = i;
			i = 0;
		}
		else if (*it == *it1)
			min = 0;

	}
	std::cout << "Shortest span : "<< min << std::endl;
}

void Span::longestSpan()
{
	if (_n.empty() || _n.capacity() < 2)
		throw std::length_error ("error : not enough number!");
	int	max = 0;
	int	i = 0;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	for (it = _n.begin(); it != _n.end(); it++)
	{
		it1 = it + 1;
		if (*it < *it1)
		{
			for((void)it; *it + i < *it1; i++)
				;
			if (max < i)
				max = i;
			i = 0;
		}
		else if (*it > *it1)
		{
			for((void)it; *it - i > *it1; i++)
				;
			if (max < i)
				max = i;
			i = 0;
		}
		else if (*it == *it1)
			max = 0;
	}
	std::cout << "Longest span :" << max << std::endl;
}
