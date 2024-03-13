#include "Bureaucrat.hpp"


int main ()
{
    Bureaucrat *test = new Bureaucrat("test", 4);

    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();

    Bureaucrat test1("hey", 4);
    std::cout << test1 << std::endl;
    std::cout << test->getName() << std::endl;
}
