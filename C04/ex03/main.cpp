#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
/*
int main() {


	return 0;
}
*/
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

//este main es para: probar la shallow o la deep copy (en el Character.cpp modificar en la sobracarga del = entre opcion shallo y opcion deep
int main() {

	Character	me("me");
	AMateria	*one = new Ice();

	me.equip(one);
	me.printPotions();
//si haces esto, el you1 lo crea con el constructor de copia
	Character you1 = me;
	std::cout << "\nEL you 1: " << std::endl;
	you1.printPotions();
	me.printPtrPotions();
	you1.printPtrPotions();
//si hago esto, el you2 lo copia al me con la sobrecarga del operador 
/*	Character you2;
	you2 = me;
	std::cout << "\nEL you 2: " << std::endl;
	you2.printPotions();
	me.printPtrPotions();
	you2.printPtrPotions();
*/
//	delete one;
//	delete you1.getPotions[0];
	return 0;
}
