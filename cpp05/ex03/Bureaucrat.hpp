#include <iostream>
#include <string>
#include <new>
#include "AForm.hpp"

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
                virtual const char *retThrow() const throw();
        };
        class GradeTooHighException: public std::exception {
            public :
                virtual const char* retThrow() const throw();
        };
	int	grade();
	const std::string getName();
	int getGrade();
	void	increaseGrade();
	void	descreaseGrade();
	void	signForm(AForm &f);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &t);

