#include "Weapon.hpp"

Weapon::Weapon (std::string _type): type(_type) {
	return;
}

Weapon::~Weapon () {
	return;
}

std::string	const& Weapon::getType (void) const {
	return (this->type);
}

void Weapon::setType (std::string _type) {
	this->type = _type;
	return;
}
