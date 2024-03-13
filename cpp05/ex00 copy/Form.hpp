#include <iostream>
#include <string>
#include <new>
#include "Bureaucrat.hpp"

class Form {
	private:
	const std::string _name;
	bool	_sign;
	const int _req;
	const int _exec;
	int	_grade;
	public:

	Form();
	Form(const std::string name, int grade);
	Form &operator=(Form &t);
	~Form();

	void GradeTooHighException();
	void GradeTooLowException();
	int	grade();
	const std::string getName();
	int getGrade();
	void	increaseGrade();
	void	descreaseGrade();
	void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream &os, Form &t);

