#include "AMateria.hpp"

//constructor & destructor
AMateria::AMateria (): type("") {

	std::cout << "Empty AMateria constructor was called" << std::endl;
	return;
}

AMateria::AMateria (std::string const &_type): type(_type) {

	std::cout << "Parameter AMateria constructor was called" << std::endl;
	return;
}

AMateria::AMateria (const AMateria &obj) {

	std::cout << "Copy AMateria constructor was called" << std::endl;
	type = obj.getType();
	return;
}

AMateria::~AMateria () {
	std::cout << "AMateria destructor was called" << std::endl;
	return;
}


//overload operators
AMateria &AMateria::operator= (const AMateria &obj) {

	std::cout << "Overload = AMateria was called" << std::endl;
	type = obj.getType();
	return *this;
}

//getters and setters
std::string		const &AMateria::getType () const {

	return type;
}

void	AMateria::setType (std::string _type) {

	type = _type;
	return;
}

//methods
void	AMateria::use(ICharacter &target) {

	std::cout << "* I don't know what I have to do with " << target.getName() << std::endl;
	return;
}
