#include "Bureaucrat.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &t);
		~ShrubberyCreationForm();
		void	function() const;
};
