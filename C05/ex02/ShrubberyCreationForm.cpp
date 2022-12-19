#include "ShrubberyCreationForm.hpp"

//constructors & destructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string reponse) : Form("ShrubberyCreationForm", 145, 137), target(reponse) {

	std::cout << "Empty ShrubberyCreationForm constructor was called\n" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {

	std::cout << "Parameter ShrubberyCreationForm constructor was called\n" << std::endl;
	target = obj.target;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << "Destructor ShrubberyCreationForm was called" << std::endl;
	return;
}

//overload operators
ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm *obj) {

	std::cout << "Operator ShrubberyCreationForm = was called\n" << std::endl;
	target = obj->target;
	return *this;
}

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
	return;
}

