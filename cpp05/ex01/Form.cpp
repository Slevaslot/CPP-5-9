#include "Form.hpp"

Form::Form() : _name ("default"),  _req(42), _exec(42)
{

}

Form::~Form()
{

}

Form::Form(const std::string name, const int req, const int exec) : _name (name), _req(req), _exec(exec)
{
	if (req > 150 || exec > 150)
		throw Form::GradeTooLowException();
	else if (exec < 1 || req < 1)
		throw Form::GradeTooHighException();
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
	if (this->_req > 150 || this->_exec > 150)
	{
		throw Form::GradeTooLowException();
		return (-1);
	}
	else if (this->_req < 1 || this->_exec < 1)
	{
		throw Form::GradeTooHighException();
		return (-1);
	}
	return (this->_req);
}

const char* Form::GradeTooHighException:: what() const throw()
{
	return "Form Grade is too high !";
}

const char* Form::GradeTooLowException:: what() const throw()
{
	return "Form Grade is too low !";
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
		std::cout << b.getName() << " cant sign " << this->getName() << " because his grade is " << b.getGrade() << " and the required grade is " << this->getReq() << std::endl;
		throw Form::GradeTooHighException();
		this->_sign = 0;
	}
}
