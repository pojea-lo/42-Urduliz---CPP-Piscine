#include "Animal.hpp"

//constructors & destructors
Animal::Animal (): type("Animal") {

	std::cout << "Empty Animal constructor was called" << std::endl;
	return;
}

Animal::Animal (std::string _type): type(_type) {

	std::cout << "Parameter Animal constructor was called" << std::endl;
	return;
}


Animal::Animal (const Animal &obj): type(obj.type) {

	std::cout << "Copy Animal constructor was called" << std::endl;
	return;
}

Animal::~Animal () {

	std::cout << "Animal destructor was called" << std::endl;
	return;
}

//getters & setters
std::string	Animal::getType() const{

	return (type);
}

void	Animal::setType(std::string _type) {

	type = _type;
	return;
}

//overload operators
Animal	&Animal::operator= (const Animal &obj) {
	
//	Animal	*neu = new Animal(obj.getType());
//	return (*neu);
	setType(obj.type);
	return *this;
}

//methods
void	Animal::makeSound() const {

	std::cout << "This class type " << getType() << " makes no idea!!!" << std::endl;
	return;
}

void	Animal::printAnimal() const {

	std::cout << "The type of this class is: " << type;
	std::cout << " the pointer of this type is: " << &type << std::endl;
}
