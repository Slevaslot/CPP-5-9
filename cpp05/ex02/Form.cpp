#include "AForm.hpp"

AForm::AForm() : _name ("default"),  _req(42), _exec(42)
{

}

AForm::~AForm()
{

}

AForm::AForm(const std::string name, const int req, const int exec) : _name (name), _req(req), _exec(exec)
{
	if (req > 150 || exec > 150)
		throw AForm::GradeTooLowException();
	else if (exec < 1 || req < 1)
		throw AForm::GradeTooHighException();
	else
		_sign = 0;
}

AForm &AForm::operator=(AForm &t)
{
	this->_sign = t._sign;
	(std::string)this->_name = t._name;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, AForm &t)
{
	// os = NULL;
	os << t.getName() << " Current sign "<< t.getSign() << "1 : can be signed" << "0 : cant be signed" << " requiered : " << t.getReq() << " grade exec : " << t.getExec() << std::endl;
	return os;
}

int	AForm::grade()
{
	if (this->_req > 150 || this->_exec > 150)
	{
		throw AForm::GradeTooLowException();
		return (-1);
	}
	else if (this->_req < 1 || this->_exec < 1)
	{
		throw AForm::GradeTooHighException();
		return (-1);
	}
	return (this->_req);
}

const char* AForm::GradeTooHighException:: what() const throw()
{
	return "AForm Grade is too high !";
}

const char* AForm::GradeTooLowException:: what() const throw()
{
	return "AForm Grade is too low !";
}

const std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSign()
{
	return (this->_sign);
}

int AForm::getExec()
{
	return (this->_exec);
}

int AForm::getReq()
{
	return (this->_req);
}


void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_req && b.getGrade() > 0)
		this->_sign = 1;
	else
	{
		std::cout << b.getName() << " cant sign " << this->getName() << " because his grade is " << b.getGrade() << " and the required grade is " << this->getReq() << std::endl;
		throw AForm::GradeTooHighException();
		this->_sign = 0;
	}
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (_sign == 0)
		std::cout << "AForm " << this->_name << "is not signed" << std::endl;
	else if (executor.getGrade() <= _req)
		this->function();
	else
		throw AForm::GradeTooHighException();
}
