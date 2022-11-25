#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main() {
/*
//programa para probar que en la sobrecarga del = estoy creando un puntero y no salta ni el constructor ni deja leaks, y el free two segundo da SEGF

   const Animal *one = new Animal("loro");
	const Animal *two = new Animal("rata");

	std::cout << "El animal one es " << one->getType() << std::endl;
	std::cout << "El animal two es " << two->getType() << std::endl;

	delete two;
	two = one;
	std::cout << "El animal two es " << two->getType() << std::endl;

	delete one;
//	delete two;
*/
/*
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* h = new WrongAnimal();
	const WrongAnimal* g = new WrongCat();

//with virtual and good results	
	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound(); //will output the dog sound!
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;

//without virtual and bad results	
	std::cout << h->getType() << " " << std::endl;
	h->makeSound();
	std::cout << g->getType() << " " << std::endl;
	g->makeSound(); //will output the Animal sound!
	std::cout << std::endl;

	delete g;
	delete h;
	delete i;
	delete j;
	delete meta;
*/
	return 0;
}
