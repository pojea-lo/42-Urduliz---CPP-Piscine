#include "Intern.hpp"

//constructors & destructors
Intern::Intern () {

	std::cout << "Empty Intern constructor was called" << std::endl;
	return;
}

Intern::Intern (const Intern &obj) {

	std::cout << "Copy Intern constructor was called" << std::endl;
	setStatus(obj.getStatus());
	return;
}

Intern::~Intern () {

	std::cout << "Intern destructor was called" << std::endl;
	return;
}

//overload operators
Intern	&Intern::operator= (const Intern &obj) {

	std::cout << "Operator Intern = was called" << std::endl;
	setStatus(obj.getStatus());
	return *this;
}

//methods
Form	*Intern::makeForm(std::string _type, std::string _target) {

	Form			*neu;
	std::string		patron[3] = {"SC", "RR", "PP"};

	int i = -1;
	while (++i < 3) {
		if (_type.compare(patron[i]) == 0)
			break;
	}
	switch (i) {
		case (0):
			std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
			neu = new ShrubberyCreationForm(_target);
			return neu;
		case (1):
			std::cout << "Intern creates Robotomy Request Form" << std::endl;
			neu = new RobotomyRequestForm(_target);
			return neu;
		case (2):
			std::cout << "Intern creates Presidential Pardon Form" << std::endl;
			neu = new PresidentialPardonForm(_target);
			return neu;
		default:
			std::cout << "\nSorry but I can't understand you.\n" << std::endl;
	}

	return 0; 
}

