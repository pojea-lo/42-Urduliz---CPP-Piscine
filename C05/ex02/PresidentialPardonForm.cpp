#include "PresidentialPardonForm.hpp"

//constructors & destructors
PresidentialPardonForm::PresidentialPardonForm(std::string reponse) : Form("PresidentialPardonForm", 25, 5), target(reponse) {

	std::cout << "Empty PresidentialPardonForm constructor was called\n" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {

	std::cout << "Parameter PresidentialPardonForm constructor was called\n" << std::endl;
	target = obj.target;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm() {

	std::cout << "Destructor PresidentialPardonForm was called" << std::endl;
	return;
}

//overload operators
PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm *obj) {

	std::cout << "Operator PresidentialPardonForm = was called\n" << std::endl;
	target = obj->target;
	return *this;
}

std::ostream	&operator<< (std::ostream &os, const PresidentialPardonForm *obj) {

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
std::string		PresidentialPardonForm::getTarget() const {

	return target;
}

void	PresidentialPardonForm::setTarget(std::string _target) {

	target = _target;
	return;
}

//methods
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {

	if (checkForm(executor, this))
		executor.executeForm(*this);
	return;
}

