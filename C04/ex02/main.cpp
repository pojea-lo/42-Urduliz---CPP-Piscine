#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main() {

//parte de no poder instanciar una clase tipo animal
//	Animal	one;

/*	int	nstr = 6;

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
*/
	Cat	one;
	Cat	two;

//	one.setIdeas();
	one.printCat();
	two = one;
	two.printCat();

/*	Cat	*one = new Cat();

	one->setIdeas();
	one->printCat();
	Cat	*two(one);
	two->printCat();

	delete one;
	delete two;
*/
	return 0;
}
