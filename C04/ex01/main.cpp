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

//prueba de deep copy - 

/*	Cat 			prueba1;
	std::cout << "\nAt first, prueba1 is: " << std::endl;
	prueba1.printCat();

	std::string		new_idea[100];
	for (int i = 0; i < 100; i++)
		new_idea[i] = "Lolo " + std::to_string(i);
	prueba1.setIdeas(new_idea);
	std::cout << "\nAnd after the change, prueba1 is: " << std::endl;
	prueba1.printCat();

//opcion con el constructor copia
//	Cat 			prueba2 (prueba1);
//opcion con el operador igual
	Cat 			prueba2;
	prueba2 = prueba1;

	std::cout << "\nAnd now, prueba2 is: " << std::endl;
	prueba2.printCat();

	std::cout << "\nMemory direction of prueba1: " << &prueba1 << std::endl;
	std::cout << "Memory direction of prueba2: " << &prueba2 << std::endl;
	prueba1.printMemoryCat();
	prueba2.printMemoryCat();
*/	
	return 0;
}
