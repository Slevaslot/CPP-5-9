#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	(std::string)this->_name = "default";
	std::cout << "Please add a grade to " << this->_name << std::endl;
	this->_grade = -1;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	(std::string)this->_name = name;
	if (grade > 150)
		this->GradeTooLowException();
	else if (grade < 1)
		this->GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &t)
{
	this->_grade = t._grade;
	(std::string)this->_name = t._name;
	return (*this);
}

int	Bureaucrat::grade()
{
	if (this->_grade > 150)
	{
		this->GradeTooLowException();
		return (-1);
	}
	else if (this->_grade < 1)
	{
		this->GradeTooHighException();
		return (-1);
	}
	return (this->_grade);
}

void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade is too high !" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade is too low !" << std::endl;
}

const std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getGrade()
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->grade() == -1)
		return ;
	--this->_grade;
}

void	Bureaucrat::descreaseGrade()
{
	if (this->grade() == -1)
		return ;
	++this->_grade;
}

