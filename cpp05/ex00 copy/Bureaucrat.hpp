#include <iostream>
#include <string>
#include <new>
#include "Form.hpp"

class Bureaucrat {
	protected:
	const std::string _name;
	int	_grade;
	public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(Bureaucrat &t);
	~Bureaucrat();

	void GradeTooHighException();
	void GradeTooLowException();
	int	grade();
	const std::string getName();
	int getGrade();
	void	increaseGrade();
	void	descreaseGrade();
	void	signForm(Form &f);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &t);

