#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n1 parte ****************" << std::endl;

	ICharacter* me = new Character("me");

	std::cout << "\n2 parte ****************" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n3 parte ****************" << std::endl;

	ICharacter* bob = new Character("bob");

	std::cout << "\n4 parte ****************" << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n5 parte ****************" << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}

/*
//este main es para: probar la shallow o la deep copy (en el Character.cpp modificar en la sobracarga del = entre opcion shallo y opcion deep
int main() {

	Character	me("me");
	AMateria	*one = new Ice();

	me.equip(one);
	me.unequip (0);//esto deja leaks de memoria
//	me.use (0, me);
	me.printPotions();
//si haces esto, el you1 lo crea con el constructor de copia
	Character you1 = me;
	std::cout << "\nEL you 1: " << std::endl;
	you1.printPotions();
	me.printPtrPotions();
	you1.printPtrPotions();
//si hago esto, el you2 lo copia al me con la sobrecarga del operador 
	Character you2;
	you2 = me;
	std::cout << "\nEL you 2: " << std::endl;
	you2.printPotions();
	me.printPtrPotions();
	you2.printPtrPotions();

//	delete one;//no hace falta, pues ya borra one via bucle del destructor del Character
	return 0;
}*/
