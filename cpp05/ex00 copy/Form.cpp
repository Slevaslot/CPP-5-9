#include "Form.hpp"

Form::Form() : _name ("default")
{
	std::cout << "Please add a grade to " << this->_name << std::endl;
	this->_grade = 42;
}

Form::~Form()
{

}

Form::Form(const std::string name, int grade) : _name (name)
{
	if (grade > 150)
		this->GradeTooLowException();
	else if (grade < 1)
		this->GradeTooHighException();
	else
		this->_grade = grade;
}

Form &Form::operator=(Form &t)
{
	this->_grade = t._grade;
	(std::string)this->_name = t._name;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Form &t)
{
	// os = NULL;
	os << t.getName() << " is "<< t.getGrade() << "/150" << std::endl;
	return os;
}

int	Form::grade()
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

void Form::GradeTooHighException()
{
	std::cout << "Grade is too high !" << std::endl;
}

void Form::GradeTooLowException()
{
	std::cout << "Grade is too low !" << std::endl;
}

const std::string Form::getName()
{
	return (this->_name);
}

int Form::getGrade()
{
	return (this->_grade);
}

void	Form::increaseGrade()
{
	if (this->grade() == -1)
		return ;
	--this->_grade;
}

void	Form::descreaseGrade()
{
	if (this->grade() == -1)
		return ;
	++this->_grade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_req)
	{
		if (b.getGrade() <= 0)
			b.grade();
		this->_sign = 1;
	}
	else
		this->_sign = 0;
}
