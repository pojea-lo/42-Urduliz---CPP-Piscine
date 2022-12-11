#include "Cat.hpp"

//constructor & destructor
Cat::Cat() {

	std::cout << "Empty Cat constructor was called" << std::endl;
	setType("Cat");
	return;
}

Cat::Cat (const Cat &obj) {

	std::cout << "Copy Cat constructor was called" << std::endl;
	setType(obj.type);
	return;
}

Cat::~Cat () {

	std::cout << "Cat destructor constructor was called" << std::endl;
	return;
}

//overload operators
Cat		&Cat::operator= (const Cat &obj) {

	type = obj.type;
	return *this;
}

//methods
void	Cat::makeSound() const {

	std::cout << "This class type " << getType() << " makes miau miau!!!" << std::endl;
	return;
}
