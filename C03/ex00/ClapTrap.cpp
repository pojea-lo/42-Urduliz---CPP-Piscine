#include "ClapTrap.hpp"

//constructor & destructor

ClapTrap::ClapTrap () {

	std::cout << "Empty constructor was called" << std::endl;
	std::string Name = "";
	this->Hitpoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap (std::string _Name) {

	std::cout << "Parameter constructor was called" << std::endl;
	this->Name = _Name;
	this->Hitpoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
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

	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << " points of damage!" << std::endl; 
	return;
}