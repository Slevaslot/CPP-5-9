#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_grade = -1;
	this->_name = "default";
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	this->_grade = grade;
	this->_name = name;
}

