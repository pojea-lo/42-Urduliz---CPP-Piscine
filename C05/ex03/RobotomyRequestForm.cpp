#include "RobotomyRequestForm.hpp"

//constructors & destructors
RobotomyRequestForm::RobotomyRequestForm(std::string reponse) : Form("RobotomyRequestForm", 72, 45), target(reponse) {

	std::cout << "Empty RobotomyRequestForm constructor was called\n" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {

	std::cout << "Parameter RobotomyRequestForm constructor was called\n" << std::endl;
	target = obj.target;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {

	std::cout << "Destructor RobotomyRequestForm was called" << std::endl;
	return;
}

//overload operators
RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm *obj) {

	std::cout << "Operator RobotomyRequestForm = was called\n" << std::endl;
	target = obj->target;
	return *this;
}

std::ostream	&operator<< (std::ostream &os, const RobotomyRequestForm *obj) {

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
std::string		RobotomyRequestForm::getTarget() const {

	return target;
}

void	RobotomyRequestForm::setTarget(std::string _target) {

	target = _target;
	return;
}

//methods
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {

	if (checkForm(executor, this))
		executor.executeForm(*this);
	return;
}

