#include "Bureaucrat.hpp"


int main ()
{
    Bureaucrat *test = new Bureaucrat("test", 4);

    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();
    test->increaseGrade();

    std::cout << test->getGrade() << std::endl;
    std::cout << test->getName() << std::endl;
}