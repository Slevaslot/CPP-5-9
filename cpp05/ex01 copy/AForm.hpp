#include <iostream>
#include <string>
#include <new>
// #include "Bureaucrat.hpp"
class Bureaucrat;
class AForm {
	private:
	const std::string _name;
	bool	_sign;
	const int _req;
	const int _exec;
	public:

	AForm();
	AForm(const std::string name, const int _req, const int _exec);
	AForm &operator=(AForm &t);
	~AForm();

	void GradeTooHighException();
	void GradeTooLowException();
	int	grade();
	const std::string getName();
	int getSign();
	void beSigned(Bureaucrat &b);
	int getExec();
	virtual void	function() const = 0;
	int getReq();
};

std::ostream& operator<<(std::ostream &os, AForm &t);

