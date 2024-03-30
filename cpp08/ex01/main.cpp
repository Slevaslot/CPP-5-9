#include "Span.hpp"

int main()
{
	Span sp = Span(10005);
	try {
		sp.addNumber(4);
		sp.addNumber(12);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp.shortestSpan();
	try {
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		for(int i = 0; i < 10000; i++)
		{
			sp.addNumber();
		}
		sp.shortestSpan();
		sp.longestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span sp1 = Span(10);
	std::vector<int> v(5, 0);
	try {
		sp1.addNumber(v.begin(), v.end());
		sp1.shortestSpan();
		sp1.longestSpan();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
