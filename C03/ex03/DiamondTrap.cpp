#include "DiamondTrap.hpp"

//constructor & destructor
DiamondTrap::DiamondTrap () {

	std::cout << "Empty DiamondTrap constructor was called" << std::endl;
	Name = "";
	ClapTrap::setName("_clap_name");
	setHitpoints(FlagTrap::getHitpoints());
	setEnergyPoints (ScravTrap::getEnergyPoints());
	setAttackDamage (FlagTrap::getAttackDamage());
	return;
}

DiamondTrap::DiamondTrap (std::string _Name) {

	std::cout << "Parameter DiamondTrap constructor was called" << std::endl;
	Name = _Name;
	ClapTrap::setName(Name + "_clap_name");
	setHitpoints(FlagTrap::getHitpoints());
	setEnergyPoints(ScravTrap::getEnergyPoints());
	setAttackDamage(FlagTrap::getAttackDamage());
	return;
}

DiamondTrap::DiamondTrap (const DiamondTrap &obj): ClapTrap(obj) {

	std::cout << "Copy DiamondTrap constructor was called" << std::endl;
	return;
}

DiamondTrap::~DiamondTrap () {

	std::cout << "DiamondTrap destructor was called" << std::endl;
	return;
}

//member functions
void	DiamondTrap::printClap() {

	std::cout << Name << " with ClapName " << ClapTrap::getName() << " has:\n";
	std::cout << getHitpoints() << " points of life\n";
	std::cout << getEnergyPoints() << " points of reserved life\n";
	std::cout << getAttackDamage() << " points of firepower\n" << std::endl;
	return;
}

void	DiamondTrap::attack(std::string const &target) {

	ScravTrap::attack(target);
	return;
}

void	DiamondTrap::whoAmI () {

	std::cout << "Hi, I am " << Name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
	return;
}
