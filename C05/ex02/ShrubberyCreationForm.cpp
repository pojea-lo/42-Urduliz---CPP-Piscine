#include "ShrubberyCreationForm.hpp"

//constructors & destructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("") {

	std::cout << "Empty ShrubberyCreationForm constructor was called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << "Destructor ShrubberyCreationForm was called" << std::endl;
	return;
}

//overload operators
std::ostream	&operator<< (std::ostream &os, const ShrubberyCreationForm *obj) {

	os << "\n" << obj->getName() << " has the next information:\n";
	os << "Grade to sign:    " << obj->getGradeToSign() << std::endl;
	os << "Grade to execute: " << obj->getGradeToExecute() << std::endl;
	os << "Status: ";

	if (obj->getStatus())
		os << "Signed" << std::endl;
	else
		os << "No signed" << std::endl;

	os << "Target: " << obj->getTarget() << std::endl;

	return os;
}

//getters & setters
std::string		ShrubberyCreationForm::getTarget() const {

	return target;
}

void	ShrubberyCreationForm::setTarget(std::string _target) {

	target = _target;
	return;
}

//methods
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

	if (checkForm(executor, this))
		executor.executeForm(*this);
	else
		std::cout << "Stich" << std::endl;
	return;
}

