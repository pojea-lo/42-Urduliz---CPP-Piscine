#include "Dog.hpp"

Dog::Dog() {

	std::cout << "Empty Dog constructor was called" << std::endl;
	setType("Dog");
	cer = new Brain();
	return;
}

Dog::Dog (const Dog &obj) {

	std::cout << "Copy Dog constructor was called" << std::endl;
	setType(obj.type);
	cer = new Brain();
	*cer = *obj.cer;
	return;
}

Dog::~Dog () {

	std::cout << "Dog destructor was called" << std::endl;
	delete cer;
	return;
}

//overload operators
Dog		&Dog::operator= (const Dog &obj) {

	type = obj.type;
	*cer = *obj.cer;
	return *this;
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
