#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main() {

	int	nstr = 6;

	Animal *str[nstr];

	for (int i = 0; i < nstr; i++) {
		if (i % 2 == 0)
			str[i] = new Cat();
//prueba a intentar crear un objeto Animal y no nos va a dejar compilar
//			str[i] = new Animal();
		else
			str[i] = new Dog();
	}

	for (int i = 0; i < nstr; i++) 
		str[i]->makeSound();

	for (int i = 0; i < nstr; i++) 
		delete str[i];
/*
//prueba de la deep copy	
	Cat	one;
	Cat	two;

	one.printCat();
	two = one;
	two.printCat();
*/
//Y si trabajásemos con punteros, estaríamos llamando a los constructores por defecto y el copia del propio C, que por defecto hace una shallow copy
/*	Cat	*one = new Cat();

	one->printCat();
	Cat	*two(one);
	two->printCat();

	delete one;
//	delete two;//esto da SGF
*/
	return 0;
}
