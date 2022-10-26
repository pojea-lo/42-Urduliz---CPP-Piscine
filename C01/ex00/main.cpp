#include "Zombie.hpp"

int	main(void) {

	Zombie	*p;

	std::cout << "First, we use the newZombie function:" << std::endl;
	p = newZombie ("Lilo");
	p->announce();
	delete p;

	std::cout << std::endl << "Then we use the randomChump function:" << std::endl;
	p = newZombie ("Stich");
	delete p;
	
	return (0);
}
