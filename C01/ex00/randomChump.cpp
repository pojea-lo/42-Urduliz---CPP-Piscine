#include "Zombie.hpp"

void randomChump(std::string name) {

	Zombie* actual = new Zombie(name);
	actual->announce();

	return;
}
