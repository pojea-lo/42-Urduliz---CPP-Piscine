#include "Form.hpp"

//constructors & destructors
Form::Form () : name(""), status(false), GradeToSign(1), GradeToExecute(1) {

	std::cout << "Empty Form constructor was called" << std::endl;
	return;
}

Form::Form (const std::string _name, int _GradeToSign, int _GradeToExecute) : name(_name), status(false), GradeToSign(_GradeToSign), GradeToExecute(_GradeToExecute) {

	std::cout << "\nParameter Form constructor was called" << std::endl;
	try {
		if (GradeToSign > 150) {
			(int &) GradeToSign = 150;
			throw GradeTooLowException();
		}
		else if (GradeToSign < 1) {
			(int &) GradeToSign = 1;
			throw GradeTooHighException();
		}
		else if (GradeToExecute > 150) {
			(int &) GradeToExecute = 150;
			throw GradeTooLowException();
		}
		else if (GradeToExecute < 1) {
			(int &) GradeToExecute = 1;
			throw GradeTooLowException();
		}
	}
	catch (std::exception &ex) {
		std::cout << "You have exceed the posible limits, because: " << ex.what() << std::endl;
	}
	return;
}

Form::Form (const Form &obj) : name(obj.name), status(obj.status), GradeToSign(obj.GradeToSign), GradeToExecute(obj.GradeToExecute) {

	std::cout << "Copy Form constructor was called" << std::endl;
	return;
}

Form::~Form() {

	std::cout << "Form destructor was called" << std::endl;
	return;
}

//overload operators
Form		&Form::operator= (const Form &obj) {

	std::cout << "Overload Form = was called" << std::endl;
	status = obj.status;
	return *this;
}

std::ostream	&operator<< (std::ostream &os, const Form &obj) {

	os << "\n" << obj.getName() << " has the next information:\n";
	os << "Grade to sign:    " << obj.getGradeToSign() << std::endl; 
	os << "Grade to execute: " << obj.getGradeToExecute() << std::endl; 
	os << "Status: ";

	if (obj.getStatus())
		os << "Signed" << std::endl;
	else
		os << "No signed" << std::endl;

	return os;
}

//getters and setters
std::string		Form::getName() const {

	return name;
}

bool 	Form::getStatus() const {

	return status;
}

int		Form::getGradeToSign() const {

	return GradeToSign;
}

int		Form::getGradeToExecute() const {

	return GradeToExecute;
}

void	Form::setName(std::string _name) {

	(std::string &)name = _name;
	return;
}

void	Form::setStatus(bool _status) {

	status = _status;
	return;
}

void	Form::setGradeToSign(int _n) {

	(int &)GradeToSign = _n;
	return;
}

void	Form::setGradeToExecute(int _n) {

	(int &)GradeToExecute = _n;
	return;
}

//methods
void	Form::beSigned(const Bureaucrat &obj) {

	try {
		if (GradeToSign >= obj.getGrade() && status == 0) {
			setStatus(true);
			obj.signForm(*this);
		}
		else if (status == 1)
			std::cout << "\nForm signed yet\n" << std::endl;
		else {
			obj.signForm(*this);
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception &ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return;
}

bool	Form::checkForm(const Bureaucrat &executor, const Form *form) const {

	try {
		if (form->getStatus())
			std::cout << "Form " << form->getName() << " is signed" << std::endl;
		else
			throw 1;

		if (executor.getGrade() <= form->getGradeToExecute())
			std::cout << executor.getName() << " can execute the form " << form->getName() << "\n" << std::endl;
		else
			throw 2;
	}
	catch (int ex) {
		if (ex == 1) 
			std::cout << "Form " << form->getName() << " is NOT signed. I can't execute it\n" << std::endl;
		else if (ex == 2) 
			std::cout << executor.getName() << " doesn't have enough grade to execute the form " << form->getName() << "\n" << std::endl;

		return false;
	}

	return true;
}
