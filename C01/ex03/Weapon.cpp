#include "Weapon.hpp"

Weapon::Weapon (std::string _type): type(_type) {
	return;
}

Weapon::~Weapon () {
	return;
}

std::string	getType (void) {
	return type;
}

void setType (std::string _type) {
	this->type = _type;
	return;
}

#endif
