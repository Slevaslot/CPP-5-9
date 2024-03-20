#include "Bureaucrat.hpp"

AForm::AForm() : _name ("default"),  _req(42), _exec(42)
{

}

AForm::~AForm()
{

}

void AForm::execute(Bureaucrat const & executor)
{
	if (_sign == 0)
		std::cout << "Form " << this->_name << "is not signed" << std::endl;
	if (executor.getGrade())
}

AForm::AForm(const std::string name, const int req, const int exec) : _name (name), _req(req), _exec(exec)
{
	if (req > 150 || exec > 150)
		this->GradeTooLowException();
	else if (exec < 1 || req < 1)
		this->GradeTooHighException();
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

void AForm::GradeTooHighException()
{
	std::cout << "AForm's grade is too high !" << std::endl;
}

void AForm::GradeTooLowException()
{
	std::cout << "AForm's is too low !" << std::endl;
}

const std::string AForm::getName()
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
		b.grade();
		this->_sign = 0;
	}
}
