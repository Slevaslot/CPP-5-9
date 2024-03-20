#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <new>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureaucrat {
	protected:
	const std::string _name;
	int	_grade;
	public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(Bureaucrat &t);
	~Bureaucrat();

	        class GradeTooLowException: public std::exception {
            public :
                virtual const char *what() const throw();
        };
        class GradeTooHighException: public std::exception {
            public :
                virtual const char* what() const throw();
        };
	int	grade();
	const std::string getName();
	int getGrade();
	void	increaseGrade();
	void	descreaseGrade();
	void	signForm(Form &f);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &t);

#endif
