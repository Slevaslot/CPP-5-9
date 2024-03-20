#include "Bureaucrat.hpp"


int main ()
{
   Bureaucrat test("test", 4);

    test.increaseGrade();
    try {
        Form testform("formTest", 0, 3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
