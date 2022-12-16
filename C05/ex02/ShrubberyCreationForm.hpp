#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

	private:
		std::string		target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();

		ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &obj);

		std::string		getTarget() const;
		void			setTarget(std::string _target);

		void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<< (std::ostream &os, const ShrubberyCreationForm *obj);

#endif
