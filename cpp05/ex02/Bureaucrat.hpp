#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPPP

#include <iostream>
#include <string>
#include <new>
#include "AForm.hpp"

class AForm;
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
                virtual const char *what() const throw();
        };
	int	grade();
	const std::string getName();
	int getGrade();
	void	increaseGrade();
	void	descreaseGrade();
	void	signForm(AForm &f);
	void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &t);

#endif
