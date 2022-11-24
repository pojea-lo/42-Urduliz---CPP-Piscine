#include "Dog.hpp"

Dog::Dog() {

	setType("Dog");
	std::cout << "Empty Dog constructor was called" << std::endl;
	return;
}

Dog::Dog (const Dog &obj) {

	setType(obj.type);
	std::cout << "Copy Dog constructor was called" << std::endl;
	return;
}

Dog::~Dog () {

	std::cout << "Dog destructor constructor was called" << std::endl;
	return;
}

//getters & setters
std::string	Dog::getType() const{

	return (type);
}

void	Dog::setType(std::string _type) {

	type = _type;
	return;
}

//methods
void	Dog::makeSound() const {

	std::cout << "This class type " << getType() << " makes guauguau!!!" << std::endl;
	return;
}
