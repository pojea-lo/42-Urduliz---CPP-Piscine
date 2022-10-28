#include "HumanB.hpp"

//constructor and destructor
HumanB::HumanB (std::string _name) : weaponB("") , name(_name) {

	std::cout << "B constructor called" << std::endl;
	return;
}

//destructor
HumanB::~HumanB () {

	return;
}

//setter
void	setWeapon (Weapon _weaponB) {

	this->weaponB = _weaponB;
	return;
}

//metodo
void	attack() const {
	
	std::cout << this->name << " attacks with his " << this->weaponB << std::endl;

	return;
}
