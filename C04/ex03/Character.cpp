#include "Character.hpp"

//constructor & destructor
Character::Character () {

	std::cout << "Empty Character constructor was called" << std::endl;
	for (int i = 0; i < 4; i++)
		potions[i] = NULL;
	Name = "";
	return;
}

Character::Character (std::string _Name) {

	std::cout << "Parameter Character constructor was called" << std::endl;
	for (int i = 0; i < 4; i++)
		potions[i] = NULL;
	Name = _Name;
	return;
}

Character::Character (const Character &obj) {

	std::cout << "Copy Character constructor was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (obj.potions[i] != NULL)
			potions[i] = obj.potions[i];
	}
	Name = obj.Name;
	return;
}

Character::~Character () {

	std::cout << "Character destructor was called" << std::endl;
	return;
}

//methods
void		Character::printPotions() const {

	for (int i = 0; i < 4; i++) {
		if (potions[i] != NULL)
			std::cout << potions[i]->getType() << std::endl;
		else
			std::cout << "Potions are empty!!" << std::endl;
	}
	return;
}
