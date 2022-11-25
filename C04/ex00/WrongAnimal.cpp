#include "WrongAnimal.hpp"

//constructors & destructors
WrongAnimal::WrongAnimal (): type("WrongAnimal") {

	std::cout << "Empty WrongAnimal constructor was called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal (std::string _type): type(_type) {

	std::cout << "Parameter WrongAnimal constructor was called" << std::endl;
	return;
}


WrongAnimal::WrongAnimal (const WrongAnimal &obj): type(obj.type) {

	std::cout << "Copy WrongAnimal constructor was called" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal () {

	std::cout << "WrongAnimal destructor was called" << std::endl;
	return;
}

//getters & setters
std::string	WrongAnimal::getType() const{

	return (type);
}

void	WrongAnimal::setType(std::string _type) {

	type = _type;
	return;
}

//overload operators
WrongAnimal	&WrongAnimal::operator= (const WrongAnimal &obj) {
	
	WrongAnimal	*neu = new WrongAnimal(obj.getType());
	return (*neu);
}

//methods
void	WrongAnimal::makeSound() const {

	std::cout << "This class type " << getType() << " makes no idea!!!" << std::endl;
	return;
}
