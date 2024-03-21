#include "AForm.hpp"

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
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
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
		throw Bureaucrat::GradeTooLowException();
		return (-1);
	}
	else if (this->_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return (-1);
	}
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException:: what() const throw()
{
	return "Grade is too high !";
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
	return "Grade is too low !";
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--this->_grade;
}

void	Bureaucrat::descreaseGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
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

}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}
