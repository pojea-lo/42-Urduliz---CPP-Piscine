#include "Zombie.hpp"

int	main(void) {

	Zombie	*p;

	std::cout << "We gona create a zombie horde:" << std::endl;
	p = zombieHorde (5, "Lilo");
	p->announce();
	delete p;

	return (0);
}
