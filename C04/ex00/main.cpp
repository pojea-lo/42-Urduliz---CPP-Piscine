#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main() {
/*
	const Animal *one = new Animal("loro");
	const Animal *two = new Animal("rata");

	std::cout << "El animal one es " << one->getType() << std::endl;
	std::cout << "El animal two es " << two->getType() << std::endl;

	delete two;
	two = one;
	std::cout << "El animal two es " << two->getType() << std::endl;

	delete one;
	delete two;
*/


	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* h = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound(); //will output the dog sound!
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << h->getType() << " " << std::endl;
	h->makeSound(); //will output the Animal sound!
	std::cout << std::endl;

	delete h;
	delete i;
	delete j;
	delete meta;

	return 0;
}
