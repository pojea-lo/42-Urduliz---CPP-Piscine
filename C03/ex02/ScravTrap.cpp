#include "ScravTrap.hpp"

//constructor & destructor
ScravTrap::ScravTrap() {

	std::cout << "Empty ScravTrap constructor was called" << std::endl;
	return;
}

ScravTrap::ScravTrap(std::string _Name): ClapTrap(_Name) {

	std::cout << "Parameter ScravTrap constructor was called" << std::endl;
	return;
}

ScravTrap::ScravTrap(const ScravTrap &obj): ClapTrap(obj) {
	
	std::cout << "ScravTrap copy constructor was called" << std::endl;
	return;
}

ScravTrap::~ScravTrap() {

	std::cout << "ScravTrap destructor was called" << std::endl;
	return;
}

//member functions
void    ScravTrap::attack (std::string const &target) {

	std::cout << "ScravTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	return;
}

void	ScravTrap::guardGate() {

	std::cout << getName() << " has enterred in Gate keeper mode." << std::endl;
	return;
}
