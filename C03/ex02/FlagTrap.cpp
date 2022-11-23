#include "FlagTrap.hpp"

//constructors & destructors
FlagTrap::FlagTrap () {

	std::cout << "Empty FlagTrap constructor was called" << std::endl;
	setHitpoints (100);
	setEnergyPoints (100);
	setAttackDamage (30);

	return;
}

FlagTrap::FlagTrap(std::string _Name): ClapTrap(_Name) {

	std::cout << "Parameter FlagTrap constructor was called" << std::endl;
	setHitpoints (100);
	setEnergyPoints (100);
	setAttackDamage (30);

	return;
}

FlagTrap::FlagTrap(const FlagTrap &obj): ClapTrap(obj) {

	std::cout << "Copy FlagTrap constructor was called" << std::endl;
	return;
}

FlagTrap::~FlagTrap() {
	
	std::cout << "FlagTrap destructor was called" << std::endl;
	return;
}

//member functions
void	FlagTrap::highFiveGuys() {

	std::cout << "Hi " << getName() << ", let's high five!!" << std::endl;
	return;
}
