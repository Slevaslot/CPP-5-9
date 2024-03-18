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

