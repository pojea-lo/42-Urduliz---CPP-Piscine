#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern : public Form {

	public:
		Intern();
		Intern(const Intern &obj);
		~Intern();

		Intern	&operator= (const Intern &obj);

		Form	*makeForm(const std::string _type, const std::string _target);

};

#endif
