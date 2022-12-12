#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main() {

//with virtual and good results	

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound(); //will output the dog sound!
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

//without virtual and bad results	

	const WrongAnimal* h = new WrongAnimal();
	const WrongAnimal* g = new WrongCat();
	const WrongCat* e = new WrongCat();

	std::cout << h->getType() << " " << std::endl;
	h->makeSound();
	std::cout << g->getType() << " " << std::endl;
	g->makeSound(); //will output the Animal sound!
	std::cout << e->getType() << " " << std::endl;
	e->makeSound(); //will output the WrongCat sound!
	std::cout << std::endl;

	delete g;
	delete h;
	delete e;

	return 0;
}
