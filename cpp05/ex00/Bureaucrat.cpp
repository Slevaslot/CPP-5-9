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
	if (this->_grade > 150)
		this->GradeTooLowException();
	else if (this->_grade < 1)
		this->GradeTooHighException();
	else
		this->_grade = grade;
	(std::string)this->_name = name;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &t)
{
	this->_grade = t._grade;
	(std::string)this->_name = t._name;
}

int	Bureaucrat::grade()
{
	if (this->_grade > 150)
	{
		this->GradeTooLowException();
		return (-1);
	}
	else if (this->_grade < 1)
		this->GradeTooHighException();
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
	++this->_grade;
	this->grade();
}

