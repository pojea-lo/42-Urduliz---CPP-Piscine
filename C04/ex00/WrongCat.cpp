#include "WrongCat.hpp"

//constructor & destructor
WrongCat::WrongCat() {

	setType("WrongCat");
	std::cout << "Empty WrongCat constructor was called" << std::endl;
	return;
}

WrongCat::WrongCat (const WrongCat &obj) {

	setType(obj.type);
	std::cout << "Copy WrongCat constructor was called" << std::endl;
	return;
}

WrongCat::~WrongCat () {

	std::cout << "WrongCat destructor constructor was called" << std::endl;
	return;
}

//overload operators
WrongCat		&WrongCat::operator= (const WrongCat &obj) {

	type = obj.type;
	return *this;
}

//getters & setters
std::string	WrongCat::getType() const{

	return (type);
}

void	WrongCat::setType(std::string _type) {

	type = _type;
	return;
}
/*
//methods
void	WrongCat::makeSound() const {

	Animal::makeSound();
	return;
}*/
