#include "Bureaucrat.hpp"


int main ()
{
    try {
        Bureaucrat test("test", 234);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // test->increaseGrade();
    // test->increaseGrade();
    // test->increaseGrade();
    // test->increaseGrade();
    // test->increaseGrade();

    // Bureaucrat test1("hey", 4);
    // std::cout << test1 << std::endl;
    // std::cout << test->getName() << std::endl;
}
