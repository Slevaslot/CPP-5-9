#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <new>
// #include "Bureaucrat.hpp"
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
	const std::string _name;
	bool	_sign;
	const int _req;
	const int _exec;
	public:

	Form();
	Form(const std::string name, const int _req, const int _exec);
	Form &operator=(Form &t);
	~Form();

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
	int getSign();
	void beSigned(Bureaucrat &b);
	int getExec();
	int getReq();
};

std::ostream& operator<<(std::ostream &os, Form &t);

#endif
