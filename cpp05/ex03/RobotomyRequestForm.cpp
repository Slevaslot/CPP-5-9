#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
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
	if ((test % 2) == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomized failed on " << _target << std::endl;
}

int	RobotomyRequestForm::grade()
{
	if (this->getExec() < 45)
	{
		throw RobotomyRequestForm::GradeTooHighException();
		return (-1);
	}
	else if (this->getReq()> 72)
	{
		throw RobotomyRequestForm::GradeTooLowException();
		return (-1);
	}
	return (this->getExec());
}

