#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		std::string		target;

	public:
		RobotomyRequestForm(std::string reponse);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();

		RobotomyRequestForm		&operator=(const RobotomyRequestForm *obj);

		std::string		getTarget() const;
		void			setTarget(std::string _target);

		void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<< (std::ostream &os, const RobotomyRequestForm *obj);

#endif
