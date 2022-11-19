#include "ClapTrap.hpp"

//constructor & destructor

ClapTrap::ClapTrap () {

    std::cout << "Empty constructor was called" << std::endl;
    std::string Name = "Parameter of constructor";
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
    std::string Name = obj.Name;
    this->Hitpoints = obj.Hitpoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return;
}

ClapTrap    &ClapTrap::operator= (const ClapTrap &obj) {

    std::cout << "Overload operator = called" << std::endl;
    std::string Name = obj.getName();
    this->Hitpoints = obj.Hitpoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return (*this);    
}

std::string ClapTrap::getName() const{

    return this->Name;
}

void    ClapTrap::setName(std::string _Name) {

    std::string Name = _Name;
    return;
}