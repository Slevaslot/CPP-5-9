#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5)
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5)
{
	_target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &t)
{
	_target = t._target;
	return (*this);
}

void RobotomyRequestForm::function() const
{
	srand(time(NULL));
	int test = std::rand();
	std::cout << test << std::endl;
	if ((test % 2) == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomized failed on " << _target << std::endl;
}

