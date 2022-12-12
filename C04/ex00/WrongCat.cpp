#include "WrongCat.hpp"

//constructor & destructor
WrongCat::WrongCat() {

	std::cout << "Empty WrongCat constructor was called" << std::endl;
	setType("WrongCat");
	return;
}

WrongCat::WrongCat (const WrongCat &obj) {

	std::cout << "Copy WrongCat constructor was called" << std::endl;
	setType(obj.type);
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

//methods
void	WrongCat::makeSound() const {

	std::cout << "This class type " << getType() << " makes wrongmiau wrongmiau!!!" << std::endl;
	return;
}
