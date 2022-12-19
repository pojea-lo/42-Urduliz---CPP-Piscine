#include "Bureaucrat.hpp"

//constructors & destructors
Bureaucrat::Bureaucrat(): Name(""), Grade(150) {

	std::cout << "Empty Bureaucrat constructor was called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string _Name, int _Grade): Name(_Name) {

	std::cout << "\nParameter Bureaucrat constructor was called" << std::endl;
	setGrade(_Grade, "new");
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): Name(obj.Name), Grade(obj.Grade) {

	std::cout << "Copy Bureaucrat constructor was called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat() {

	std::cout << "Destructor Bureaucrat was called" << std::endl;
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
	catch (std::exception &exb) {
		std::cout << "\nError: " << exb.what() << std::endl;
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

void	Bureaucrat::beSigned(Form &obj) {

	try {
		if (Grade <= obj.getGradeToSign() && obj.getStatus() == 0) {
			obj.setStatus(true);
			signForm(obj);
		}
		else if (obj.getStatus() == 1)
			std::cout << "\nForm signed yet\n" << std::endl;
		else {
			signForm(obj);
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception &ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return;
}

void	Bureaucrat::signForm(const Form &obj) const {

	if (obj.getStatus())
		std::cout << "\n" << Name << " signs " << obj.getName() << "\n" << std::endl;
	else
		std::cout << "\n" << Name << " cannot sign " << obj.getName() << " beacause: " << std::endl;

	return;
}

void	Bureaucrat::executeForm(const Form &obj) const {

	try {
		if (obj.getName().compare("ShrubberyCreationForm") == 0) {
			std::string	file_name = obj.getTarget() + "_shrubbery";
			std::ofstream file(file_name);
			if (!file)
				throw 1;
			file << "         _-_        " << std::endl;
			file << "      /~~   ~~\\     " << std::endl;
			file << "   /~~         ~~\\  " << std::endl;
			file << "  {               } " << std::endl;
			file << "   \\  _-     -_  /  " << std::endl;
			file << "     ~  \\\\ //  ~    " << std::endl;
			file << "  _- -   | | _- _   " << std::endl;
			file << "    _ -  | |   -_   " << std::endl;
			file << "        // \\\\       " << std::endl;
			file.close();
		}

		else if (obj.getName().compare("RobotomyRequestForm") == 0) {
			std::cout << "\a";
			std::cout << obj.getTarget() << " has been robotomized successfully 50\% of the time\n" << std::endl;
		}

		else if (obj.getName().compare("PresidentialPardonForm") == 0) {
			std::cout << "***************************************************" << std::endl;
			std::cout << "*                                                 *" << std::endl;
			std::cout << "* " <<  obj.getTarget() << " has been pardones by Zafod Beeblebrox." << std::endl;
			std::cout << "*                                                 *" << std::endl;
			std::cout << "***************************************************" << std::endl;
		}
		std::cout << Name << " executes " << obj.getName() << "\n" << std::endl;
	}
	catch (int ex) {
		if (ex == 1)
			std::cout << "I don't know, but I can't open more files!!" << std::endl;
	}
	return;
}
