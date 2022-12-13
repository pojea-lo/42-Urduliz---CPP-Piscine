#include "Cat.hpp"

//constructor & destructor
Cat::Cat() {

	std::cout << "Empty Cat constructor was called" << std::endl;
	setType("Cat");
	cerebro = new Brain();
	return;
}

Cat::Cat (const Cat &obj) {

	std::cout << "Copy Cat constructor was called" << std::endl;
	setType(obj.type);
	cerebro = new Brain();
	*cerebro = *obj.cerebro;
	return;
}

Cat::~Cat () {

	std::cout << "Cat destructor was called" << std::endl;
	delete cerebro;
	return;
}

//overload operators
Cat		&Cat::operator= (const Cat &obj) {

	std::cout << "Overload operator = was called" << std::endl;
	type = obj.type;
	*cerebro = *obj.cerebro;
	return *this;
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

void	Cat::printCat() const {

	std::cout << "The type of this class is: " << type;
	std::cout << " the pointer of this type is: " << &type;
	std::cout << " and the pointer of the brain is: ";
	cerebro->printPtrBrain ();
	std::cout << std::endl;
}
