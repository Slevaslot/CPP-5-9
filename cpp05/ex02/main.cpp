#include "PresidentialPardonForm.hpp"
int main ()
{
   Bureaucrat test("test", 4);

    test.increaseGrade();
    std::cout << test << std::endl;
    AForm *testform = new PresidentialPardonForm("Home");
    AForm *testform1 = new RobotomyRequestForm("robot");
    // testform->function();
    testform1->beSigned(test);
    testform->beSigned(test);
    test.signForm(*testform);
    test.signForm(*testform1);
    Bureaucrat test1("hey", 4);
    std::cout << test1 << std::endl;
    std::cout << test.getName() << std::endl;
}
