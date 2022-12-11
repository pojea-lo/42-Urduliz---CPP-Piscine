#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main() {

	int	nstr = 6;

	Animal *str[nstr];

	for (int i = 0; i < nstr; i++) {
		if (i % 2 == 0)
			str[i] = new Cat();
		else
			str[i] = new Dog();
	}

	for (int i = 0; i < nstr; i++) 
		str[i]->makeSound();

	for (int i = 0; i < nstr; i++) 
		delete str[i];
/*
	Cat prueba1;
	Cat prueba2 (prueba1);

	std::cout << &prueba1 << std::endl;
	std::cout << &prueba2 << std::endl;
	prueba1.printCat();
	prueba2.printCat();

	Animal 	aprueba1;
	Animal	aprueba2 (aprueba1);
	Animal	aprueba3 = aprueba1;

	std::cout << &aprueba1 << std::endl;
	std::cout << &aprueba2 << std::endl;
	std::cout << &aprueba3 << std::endl;
	aprueba1.printAnimal();
	aprueba2.printAnimal();
	aprueba3.printAnimal();
*/
	return 0;
}
