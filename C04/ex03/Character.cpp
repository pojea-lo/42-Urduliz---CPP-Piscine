#include "Character.hpp"

//constructor & destructor
Character::Character () { //: potion{} {

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
			potions[i] = obj.potions[i]->clone();//deep copy
//			potions[i] = obj.potions[i];//shallow copy

		else
			potions[i] = NULL; 
	}
	Name = obj.Name;
	return;
}

Character::~Character () {

	std::cout << "Character destructor was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (potions[i] != NULL)
			delete potions[i];
	}
	return;
}

//overload operators
Character	&Character::operator= (const Character &obj) {

	std::cout << "Overload Character = was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (obj.potions[i] != NULL)
			potions[i] = obj.potions[i]->clone();//deep copy
//			potions[i] = obj.potions[i];//shallow copy
		else
			potions[i] = NULL; 
	}
	Name = obj.Name;
	return *this;
}

//getter & setter
std::string	const &Character::getName() const {

	return Name;
}

void	Character::setName(std::string const &_Name) {

	Name = _Name;
	return;
}

AMateria	&Character::getPotions(int idx) {

	return *potions[idx];
}

//methods
void	Character::equip(AMateria *m) {

	int	i = 0;
	while (i < 4) {
		if (potions [i] == NULL) {
			std::cout << m->getType() << " was added to your potions" << std::endl;
			potions[i] = m;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "Sorry, but your potions are completed" << std::endl;
	return;
}

void	Character::unequip (int idx) {

	if (idx >= 0 && idx < 4) {
		if (potions[idx] != NULL) {
			potions[idx] = NULL;
			std::cout << "The id " << idx << " was unequiped of your potions!!" << std::endl;
		}
		else
			std::cout << "The id " << idx << " was empty yet!!" << std::endl;
	}
	else
		std::cout << "Sorry, but your idx exceed the good number!!" << std::endl;
	return;
}

void	Character::use (int idx, ICharacter &target) {

	if (potions[idx] != NULL) {
		delete potions[idx];
		potions[idx]->use(target);
	}
	else
		std::cout << "Sorry, but ther's no potion with this id" << std::endl;
	return;
}

void	Character::printPotions() const {

	std::cout << "Your potions list are:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (potions[i] != NULL)
			std::cout << "Id " << i << ": " << potions[i]->getType() << std::endl;
		else
			std::cout << "Id " << i << ": " << "Empty!!" << std::endl;
	}
	return;
}

void	Character::printPtrPotions() const {
	
	std::cout << "Your ptr of potions[0] is:" << &potions[1]->getType() << "y luego viene el type: " << &potions[0]->getType() << std::endl;
	return;
}
