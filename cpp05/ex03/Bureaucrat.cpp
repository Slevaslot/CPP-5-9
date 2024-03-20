#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name ("default")
{
	std::cout << "Please add a grade to " << this->_name << std::endl;
	this->_grade = 42;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name (name)
{
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

std::ostream& operator<<(std::ostream &os, Bureaucrat &t)
{
	// os = NULL;
	os << t.getName() << " is "<< t.getGrade() << "/150" << std::endl;
	return os;
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

void	Bureaucrat::signForm(AForm &f)
{
	if (f.getSign() == 1)
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else
	{
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because ";
		this->grade();
	}
	f.function();

}
