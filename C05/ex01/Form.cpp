#include "Form.hpp"

//constructors & destructors
Form::Form () : name("Magnific form"), status(false), GradeToSign(5), GradeToExecute(2) {

	std::cout << "Empty Form constructor was called" << std::endl;
	return;
}

Form::Form (const std::string _name, const int _GradeToSign, const int _GradeToExecute) : name(_name), status(false), GradeToSign(_GradeToSign), GradeToExecute(_GradeToExecute) {

	std::cout << "Parameter Form constructor was called" << std::endl;
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

	os << obj.getName() << " has the next information:\n";
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


