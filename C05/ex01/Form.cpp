#include "Form.hpp"

//constructors & destructors
Form::Form () : name("Magnific form"), status(false), GradeToSign(1), GradeToExecute(1) {

	std::cout << "Empty Form constructor was called" << std::endl;
	return;
}

Form::Form (const std::string _name, int _GradeToSign, int _GradeToExecute) : name(_name), status(false), GradeToSign(_GradeToSign), GradeToExecute(_GradeToExecute) {

	std::cout << "\nParameter Form constructor was called" << std::endl;
	try {
		if (GradeToSign < 1) {
			_GradeToSign = 1;
			std::cout << "Grade To Sign: ";
			throw GradeTooHighException();
		}
		if (GradeToSign > 150) {
			_GradeToSign = 150;
			std::cout << "Grade To Sign: ";
			throw GradeTooLowException();
		}
		if (GradeToExecute < 1) {
	//		(int) GradeToExecute = 1;
			std::cout << "Grade To Execute: ";
			throw GradeTooHighException();
		}
		if (GradeToExecute > 150) {
	//		(int) GradeToExecute = 150;
			std::cout << "Grade To Execute: ";
			throw GradeTooLowException();
		}
	}
	catch (std::exception &exf) {
		std::cout << _GradeToSign << std::endl;
		std::cout << "Error: " << exf.what() << std::endl;
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

	return GradeToSign;
}

int		Form::getGradeToExecute() const {

	return GradeToExecute;
}

void	Form::setStatus() {

	status = true;
	return;
}
/*
void	Form::setGradeToSign(int n) {

	static_cast<int>(GradeToSign) = n;
	return;
}*/
