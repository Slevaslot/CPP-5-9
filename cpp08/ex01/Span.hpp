#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
class Span
{
	private :
		std::vector<int> _n;
		unsigned int _max;

	public :
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		void addNumber();
		void addNumber(int n);
		void shortestSpan();
		void longestSpan();
		void addNumber(int begin, int end);
};

#endif
