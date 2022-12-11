#include "Dog.hpp"

//constructor and destructor
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

//overload operators
Dog		&Dog::operator= (const Dog &obj) {

	type = obj.type;
	return *this;
}


//methods
void	Dog::makeSound() const {

	std::cout << "This class type " << getType() << " makes guauguau!!!" << std::endl;
	return;
}
