#include "Bureaucrat.hpp"

//constructors & destructors
Bureaucrat::Bureaucrat() {

	std::cout << "Empty constructor was called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string _Name, size_t _Grade) {

	std::cout << "Parameter constructor was called" << std::endl;
	Name = _Name;
	Grade = _Grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {

	std::cout << "Empty constructor was called" << std::endl;
	Name = obj.Name;
	Grade = obj.Grade;
	return;
}

Bureaucrat::~Bureaucrat() {

	std::cout << "Destructor was called" << std::endl;
	return;
}

//overload operators
Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &obj) {

	std::cout << "Empty constructor was called" << std::endl;
	Name = obj.Name;
	Grade = obj.Grade;
	return *this;
}

//getters & setters
std::string		Bureaucrat::getName() {

	return Name;
}

void	Bureaucrat::setName(std::string _Name) {

	Name = _Name;
	return;
}

size_t	Bureaucrat::getGrade () {

	return Grade;
}

void	Bureaucrat::setGrade(size_t _Grade) {

	Grade = _Grade;
	return;
}

//methods
