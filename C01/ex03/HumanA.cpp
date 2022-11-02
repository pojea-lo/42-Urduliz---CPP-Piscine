#include "HumanA.hpp"

//constructor and destructor
HumanA::HumanA (std::string _name, Weapon &_weaponA) : name(_name), weaponA(_weaponA) {

	std::cout << "A constructor called" << std::endl;
	return;
}

//destructor
HumanA::~HumanA () {

	std::cout << "A destructor called" << std::endl;
	return;
}

//metodo
void	HumanA::attack() {
	
	std::cout << this->name << " attacks with his " << this->weaponA.getType() << std::endl;

	return;
}
