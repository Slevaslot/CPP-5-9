#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &t)
{
	_target = t._target;
	return (*this);
}

void PresidentialPardonForm::function() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

int	PresidentialPardonForm::grade()
{
	if (this->getExec() < 5)
	{
		this->GradeTooHighException();
		return (-1);
	}
	else if (getReq()> 25)
	{
		this->GradeTooLowException();
		return (-1);
	}
	return (this->getExec());
}
