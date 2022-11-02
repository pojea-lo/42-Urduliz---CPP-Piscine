#include "HumanB.hpp"

//constructor and destructor
HumanB::HumanB (std::string _name) : name(_name) {

	std::cout << "B constructor called" << std::endl;
	return;
}

//destructor
HumanB::~HumanB () {

	std::cout << "B destructor called" << std::endl;
	return;
}

//setter
void	HumanB::setWeapon (Weapon &_weaponB) {

	this->weaponB = &_weaponB;
	return;
}

//metodo
void	HumanB::attack() {
	
	std::cout << this->name << " attacks with his " << this->weaponB->getType() << std::endl;

	return;
}
