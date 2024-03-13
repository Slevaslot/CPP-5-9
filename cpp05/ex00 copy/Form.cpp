#include "Bureaucrat.hpp"

Form::Form() : _name ("default"), _exec(42)
{

}

Form::~Form()
{

}

Form::Form(const std::string name, const int req, const int exec) : _name (name), _exec(exec), _req(req)
{
	if (req > 150 || exec > 150)
		this->GradeTooLowException();
	else if (exec < 1 || req < 1)
		this->GradeTooHighException();
	else
		_sign = 0;
}

Form &Form::operator=(Form &t)
{
	this->_sign = t._sign;
	(std::string)this->_name = t._name;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Form &t)
{
	// os = NULL;
	os << t.getName() << " Current sign "<< t.getSign() << "1 : can be signed" << "0 : cant be signed" << " requiered : " << t.getReq() << " grade exec : " << t.getExec() << std::endl;
	return os;
}

int	Form::grade()
{
	if (this->_exec > 150)
	{
		this->GradeTooLowException();
		return (-1);
	}
	else if (this->_exec < 1)
	{
		this->GradeTooHighException();
		return (-1);
	}
	return (this->_exec);
}

void Form::GradeTooHighException()
{
	std::cout << "Form's grade is too high !" << std::endl;
}

void Form::GradeTooLowException()
{
	std::cout << "Form's is too low !" << std::endl;
}

const std::string Form::getName()
{
	return (this->_name);
}

int Form::getSign()
{
	return (this->_sign);
}

int Form::getExec()
{
	return (this->_exec);
}

int Form::getReq()
{
	return (this->_req);
}


void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_req && b.getGrade() > 0)
		this->_sign = 1;
	else
	{
		b.grade();
		this->_sign = 0;
	}
}
