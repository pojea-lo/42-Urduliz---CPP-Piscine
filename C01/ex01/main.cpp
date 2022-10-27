#include "Zombie.hpp"

int	main(void) {

	Zombie		*p;
	Zombie		*pb;
	std::string	res = "";

	int			nmbz = 0;

	std::cout << "We gona create a zombie horde:" << std::endl;
	std::cout << "Give me a desired number of zombies - ";
	std::cin >> res;
	nmbz = std::stoi(res);
	p = zombieHorde (nmbz, "Lilo");
	pb = p;
	for (int i = 0 ; i < nmbz; i++) {
		p->announce();
		p++;
	}
	p = pb;
	delete[] p;

	return (0);
}
