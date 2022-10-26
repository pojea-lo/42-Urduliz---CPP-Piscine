#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

	Zombie* actual = new Zombie(name);

	return (actual);
}
