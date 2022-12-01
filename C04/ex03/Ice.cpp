#include "Ice.hpp"

//constructors & destructors
Ice::Ice() {

	std::cout << "Empty Ice constructor was called" << std::endl;
	type = "ice";
	return;
}
	
Ice::Ice(std::string const &_type) {

	std::cout << "Parameter Ice constructor was called" << std::endl;
	type = _type;
	return;
}
	
Ice::Ice(const Ice &obj) {

	std::cout << "Copy Ice constructor was called" << std::endl;
	type = obj.getType();
	return;
}
	
Ice::~Ice() {

	std::cout << "Ice destructor was called" << std::endl;
	return;
}

//methods
Ice		*Ice::clone () const {

	Ice *neu = new Ice(*this);
	return neu;
}
/*
void	Ice::use(ICharacter &target) {

	std::cout << " shoots an ice bolt at " << target << std::endl;
	return;
}*/
