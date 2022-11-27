#include "Cat.hpp"

Cat::Cat() {

	std::cout << "Empty Cat constructor was called" << std::endl;
	setType("Cat");
	cer = new Brain();
	return;
}

Cat::Cat (const Cat &obj) {

	std::cout << "Copy Cat constructor was called" << std::endl;
	setType(obj.type);
	cer = new Brain();
	return;
}

Cat::~Cat () {

	std::cout << "Cat destructor constructor was called" << std::endl;
	delete cer;
	return;
}

//getters & setters
std::string	Cat::getType() const{

	return (type);
}

void	Cat::setType(std::string _type) {

	type = _type;
	return;
}

//methods
void	Cat::makeSound() const {

	std::cout << "This class type " << getType() << " makes miau miau!!!" << std::endl;
	return;
}
