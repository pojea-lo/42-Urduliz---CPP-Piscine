#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	private:
		std::string		target;

	public:
		PresidentialPardonForm(std::string reponse);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();

		PresidentialPardonForm		&operator=(const PresidentialPardonForm *obj);

		std::string		getTarget() const;
		void			setTarget(std::string _target);

		void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<< (std::ostream &os, const PresidentialPardonForm *obj);

#endif
