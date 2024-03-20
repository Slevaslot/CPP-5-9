#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &t)
{
	_target = t._target;
	return (*this);
}

void ShrubberyCreationForm::function() const
{
	std::string namef;
	namef = _target + "_shrubbery";
	const char* char_array = namef.c_str();
	std::fstream fs;
	fs.open(char_array, std::fstream::in | std::fstream::out | std::fstream::app);
	fs << 	"              * *\n"
	"           *    *  *\n"
	"      *  *    *     *  *\n"
	"     *     *    *  *    *\n"
	" * *   *    *    *    *   *\n"
	" *     *  *    * * .#  *   *\n"
	" *   *     * #.  .# *   *\n"
	"  *     \"#.  #: #\" * *    *\n"
	" *   * * \"#. ##\"       *\n"
	"   *       \"###\n"
	"             \"##\n"
	"              ##.\n"
	"              .##:\n"
	"              :###\n"
	"              ;###\n"
	"            ,####.\n"
	"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n"<< std::endl;
	fs.close();
}

