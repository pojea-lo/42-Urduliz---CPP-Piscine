#include "Bureaucrat.hpp"

//constructors & destructors
Bureaucrat::Bureaucrat(): Name(""), Grade(150) {

	std::cout << "Empty Bureaucrat constructor was called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string _Name, int _Grade): Name(_Name) {

	std::cout << "Parameter Bureaucrat constructor was called" << std::endl;
	setGrade(_Grade, "new");
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): Name(obj.Name), Grade(obj.Grade) {

	std::cout << "Copy bureaucrat constructor was called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat() {

	std::cout << "Destructor was called" << std::endl;
	return;
}

//overload operators
Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &obj) {

	std::cout << "Overload Bureaucrat = was called" << std::endl;
	Grade = obj.Grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj) {

	os << obj.getName() << " grade is " << obj.getGrade() << std::endl;
	return os;
}

//getters & setters
std::string		Bureaucrat::getName() const {

	return Name;
}

int	Bureaucrat::getGrade () const {

	return Grade;
}

void	Bureaucrat::setGrade(int _Grade, std::string str) {

	try {
		if (str.compare("new") == 0 && (_Grade < 1)) {
			Grade = 1;
			throw GradeTooHighException();
		}
		else if (str.compare("new") == 0 && (_Grade > 150)) {
			Grade = 150;
			throw GradeTooLowException();
		}
		else if (str.compare("up") == 0 && (Grade - _Grade < 1)) {
			Grade = 1;
			throw GradeTooHighException();
		}
		else if (str.compare("down") == 0 && (Grade + _Grade > 150)) {
			Grade = 150;
			throw GradeTooLowException();
		}

		if (str.compare("new") == 0)
			Grade = _Grade;
		if (str.compare("up") == 0)
			Grade -= _Grade;
		if (str.compare("down") == 0)
			Grade += _Grade;
	}
	catch (std::exception &ex) {

		std::cout << "Error: " << ex.what() << std::endl;

	}

	return;
}

//methods
void	Bureaucrat::UpGrade(int n) {

	setGrade (n, "up");
	return;
}

void	Bureaucrat::DownGrade(int n) {

	setGrade (n, "down");
	return;
}
