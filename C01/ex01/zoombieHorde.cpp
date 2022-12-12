#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	Zombie*	actual_h = new Zombie[N];//genero la horda de Zombies
	
	std::string	number = "";
	std::string	p_name = "";

	for (int i = 0; i < N; i++) {//les doy a cada uno un atributo

	//convierto el numero en cadena para pasar el nombre con numero		
		number = std::to_string(i + 1);
		p_name = name + "_" + number;
		actual_h[i].setName(p_name);
	}

	return (actual_h);
}
