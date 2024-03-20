#include "ShrubberyCreationForm.hpp"
#include <fstream>
class PresidentialPardonForm : public AForm
{
	private :
		std::string _target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm &operator=(PresidentialPardonForm &t);
		~PresidentialPardonForm();
		void	function() const;
		int	grade();
};
