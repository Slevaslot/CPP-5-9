#include "ShrubberyCreationForm.hpp"

int main ()
{
   Bureaucrat test("test", 4);

    test.increaseGrade();
    std::cout << test << std::endl;
    AForm *testform = new ShrubberyCreationForm("Home");
    testform->function();
    testform->beSigned(test);
    test.signForm(*testform);
    Bureaucrat test1("hey", 4);
    std::cout << test1 << std::endl;
    std::cout << test.getName() << std::endl;
}
