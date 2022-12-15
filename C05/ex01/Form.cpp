#include "Form.hpp"

//constructors & destructors
Form::Form () : name("Magnific form"), status(false), GradeToSign(1), GradeToExecute(1) {

	std::cout << "Empty Form constructor was called" << std::endl;
	return;
}

Form::Form (const std::string _name, int _GradeToSign, int _GradeToExecute) : name(_name), status(false), GradeToSign(_GradeToSign), GradeToExecute(_GradeToExecute) {

	std::cout << "\nParameter Form constructor was called" << std::endl;

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
Form		Form::operator= (const Form &obj) {

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

	try {
		if (GradeToSign < 1) {
			throw GradeTooHighException();
			return -1;
		}
		else if (GradeToSign > 150) {
			throw GradeTooLowException();
			return -1;
		}

		return GradeToSign;
	}
	catch (std::exception &exf) {
		std::cout << "\nSorry, but you exceed the posible limits of the grade to Sign, because: " << exf.what() << std::endl;
	}

	return -1;
}

int		Form::getGradeToExecute() const {

	try {
		if (GradeToExecute < 1) {
			throw GradeTooHighException();
			return -1;
		}
		else if (GradeToExecute > 150) {
			throw GradeTooLowException();
			return -1;
		}

		return GradeToExecute;
	}
	catch (std::exception &exf) {
		std::cout << "\nSorry, but you exceed the posible limits of the grade to Execute, because: " << exf.what() << std::endl;
	}

	return -1;
}

void	Form::setStatus() {

	status = true;
	return;
}
