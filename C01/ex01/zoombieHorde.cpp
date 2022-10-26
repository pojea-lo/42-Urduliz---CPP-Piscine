#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	std::string	number;
	std::string	p_name;
	Zombie*	actual_h = new Zombie[N];

	for (int i= 0; i < N; i++) {

//covierto el numero en cadena para pasar el nombre con numero		
		std::stringstream ns;
		ns << i;
		ns >> number;
		p_numer = 
		actual_h[i].setName(name, number);
	}

	return (actual_h);
}
