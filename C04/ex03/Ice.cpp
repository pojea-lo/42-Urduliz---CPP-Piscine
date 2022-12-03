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

//overload operators
Ice		&Ice::operator= (const Ice &obj) {

	type = obj.type;
	return *this;
}

//methods
Ice		*Ice::clone () const {

	std::cout << "Ice cloned was called" << std::endl;
	Ice *neu = new Ice(*this);
//	Ice *neu = new Ice();
	return neu;
}

void	Ice::use(ICharacter &target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}
