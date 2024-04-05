#include "Base.hpp"
#include "class/A.hpp"
#include "class/B.hpp"
#include "class/C.hpp"
#include <stdexcept>
// #include <unistd.h>

Base *generate()
{
	srand(time(NULL));
	int n = rand() % 3;
	if (n == 1)
		return (new A());
	else if (n == 2)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		A test = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
	}
	try {
		B test = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {
	}
	try {
		C test = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {
	}

}

int main()
{
	Base *test = generate();
	identify(*test);
	identify(test);
	// sleep(1);
	Base *test2 = generate();
	identify(*test2);
	identify(test2);

	delete test2;
	delete test;
}
