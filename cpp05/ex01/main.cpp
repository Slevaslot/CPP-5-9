#include "Bureaucrat.hpp"


int main ()
{
   Bureaucrat test("test", 4);

    test.increaseGrade();
    std::cout << test << std::endl;
    Form testform("formTest", 5, 3);
    testform.beSigned(test);
    test.signForm(testform);
    Bureaucrat test1("hey", 4);
    std::cout << test1 << std::endl;
    std::cout << test.getName() << std::endl;
}
