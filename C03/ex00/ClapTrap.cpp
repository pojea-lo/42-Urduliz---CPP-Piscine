#include "ClapTrap.hpp"

//constructor & destructor

ClapTrap::ClapTrap () {

	std::cout << "Empty constructor was called" << std::endl;
	std::string Name = "";
	Hitpoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap (std::string _Name) {

	std::cout << "Parameter constructor was called" << std::endl;
	Name = _Name;
	Hitpoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::~ClapTrap () {

	std::cout << "Destructor was called" << std::endl;
	return;
}

ClapTrap::ClapTrap (const ClapTrap &obj) {

	std::cout << "Copy constructor was called" << std::endl;
	this->Name = obj.Name;
	this->Hitpoints = obj.Hitpoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return;
}

//overload operators

ClapTrap    &ClapTrap::operator= (const ClapTrap &obj) {

	std::cout << "Overload operator = called" << std::endl;
	this->Name = obj.getName();
	this->Hitpoints = obj.Hitpoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return (*this);    
}

//getters & setters

std::string ClapTrap::getName() const{

	return this->Name;
}

void    ClapTrap::setName(std::string _Name) {

	std::string Name = _Name;
	return;
}

unsigned int    ClapTrap::getHitpoints() const {

	return this->Hitpoints;
}

void    ClapTrap::setHitpoints(unsigned int num) {

	this->Hitpoints = num;
	return;
}

unsigned int    ClapTrap::getEnergyPoints() const {

	return this->EnergyPoints;
}

void    ClapTrap::setEnergyPoints(unsigned int num) {

	this->EnergyPoints = num;
	return;
}

unsigned int    ClapTrap::getAttackDamage() const {

	return this->AttackDamage;
}

void    ClapTrap::setAttackDamage(unsigned int num) {

	this->AttackDamage = num;
	return;
}

//member functions

void    ClapTrap::attack (std::string const &target) {

	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	return;
}

void	ClapTrap::takeDamage (unsigned int amount) {

	std::cout << Name << " recives " << amount << " points of potential damaged!!" << std::endl;
	AttackDamage = amount;
	return;
}

void	ClapTrap::beRepaired (unsigned int amount) {

	std::cout << Name << " recives " << amount << " points of extra life!!" << std::endl;
	EnergyPoints = amount;
	if ((Hitpoints + EnergyPoints) >= 10)
		Hitpoints = 10;
	else
		Hitpoints = Hitpoints + EnergyPoints;
	return;
}

void	ClapTrap::printClap () const {

	std::cout << Name << " has:\n";
	std::cout << Hitpoints << " points of life\n";
	std::cout << EnergyPoints << " points of reserved life\n";
	std::cout << AttackDamage << " points of firepower\n" << std::endl;
	return;
}

void	ClapTrap::chHitpoints (ClapTrap const &obj) {

	if (Hitpoints < obj.AttackDamage)
		Hitpoints = 0;
	else
		Hitpoints = Hitpoints - obj.AttackDamage;
	
	return;
}
