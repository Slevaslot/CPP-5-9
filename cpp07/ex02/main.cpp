#include "Array.hpp"

int main()
{
	try {
		Array<int> test(void);
	}
	catch (std::out_of_range &e){
		std::cout << "IMPOSSIBLE TO CREATE" << std::endl;
	}
	try {
		Array<int> test(16);
		std::cout << test[2];
		test[2] = 2;
		std::cout << test[2] << std::endl;
	}
	catch (std::out_of_range &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Array<int> test(16);
		Array<int> test1;
		test1 = test;
		std::cout << test1[2];
		test1[2] = 2;
		std::cout << test1[2] << std::endl;
		test1[17] = 17;
	}
	catch (std::out_of_range &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Array<int> test(16);
		Array<int> test1(test);
		test1[2] = 2;
		std::cout << test[2] << std::endl;
	}
	catch (std::out_of_range &e){
		std::cout << e.what() << std::endl;
	}
}
