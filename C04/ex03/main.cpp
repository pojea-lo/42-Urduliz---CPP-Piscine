#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main() {

/*	Ice		one;
	Cure	three;

	Ice *two = one.clone();
	delete two;
	Cure *four = three.clone();
	delete four;
*/
	Character	me("me");
	me.printPotions();

	system ("leaks Rollomateria");
	return 0;
}



/*
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}*/
