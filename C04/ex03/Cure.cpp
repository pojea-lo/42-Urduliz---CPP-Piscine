#include "Cure.hpp"

//constructors & destructors
Cure::Cure() {

	std::cout << "Empty Cure constructor was called" << std::endl;
	type = "cure";
	return;
}
	
Cure::Cure(std::string const &_type) {

	std::cout << "Parameter Cure constructor was called" << std::endl;
	type = _type;
	return;
}
	
Cure::Cure(const Cure &obj) {

	std::cout << "Copy Cure constructor was called" << std::endl;
	type = obj.getType();
	return;
}
	
Cure::~Cure() {

	std::cout << "Cure destructor was called" << std::endl;
	return;
}

//methods
Cure		*Cure::clone () const {

	Cure *neu = new Cure(*this);
	return neu;
}

void	Cure::use(ICharacter &target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}
