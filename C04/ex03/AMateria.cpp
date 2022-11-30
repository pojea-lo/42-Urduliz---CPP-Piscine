#include "AMateria.hpp"

//constructor & destructor
AMateria::AMateria (): type("") {

	std::cout << "Empty AMateria constructor was called" << std::endl;
	return;
}

AMateria::Amateria (std::string const &_type): type(_type) {

	std::cout << "Parameter AMateria constructor was called" << std::endl;
	return;
}

AMateria::AMateria (const AMateria &obj) {

	std::cout << "Copy AMateria constructor was called" << std::endl;
	type = obj.type;
	return;
}

//overload operators
AMateria &AMateria::operator= (const AMateris &obj) {

	std::cout << "Overload = AMateria was called" << std::endl;
	neu = new AMateria(obj.type);
	return neu;
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
AMateria	*AMateria::clone() const {
	
	AMateria *neu = new AMateria ();
	return neu;
}

void	AMateria::use(ICharacter &target) {


	return;
}
