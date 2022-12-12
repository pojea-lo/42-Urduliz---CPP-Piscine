#include "Zombie.hpp"

#include <iostream>

//Constructor and destructor
Zombie::Zombie (void) {

	std::cout << this->_name << " was created with empty" << std::endl;

	return;
}

Zombie::Zombie (std::string name) {

	this->_name = name;
	std::cout << this->_name << " was created with complete" << std::endl;

	return;
}

Zombie::~Zombie (void) {

	std::cout << this->_name << " was destroyed" << std::endl;

	return;
}

//getters & setters
std::string	Zombie::getName(void) const {

	return _name;
}

void	Zombie::setName(std::string name) {

	this->_name = name;

	return;
}

//function member
void	Zombie::announce(void) const {

	std::cout << this->_name << " BrainnnnnzzzzzzzZ!!!" << std::endl;

	return;
}
