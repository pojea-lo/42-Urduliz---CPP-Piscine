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

	return 0;
}
