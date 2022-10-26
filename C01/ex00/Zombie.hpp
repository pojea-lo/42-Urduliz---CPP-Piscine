#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

	private:

		std::string	_name;

	public:

		Zombie (void);
		Zombie (std::string name);
		~Zombie (void);

		std::string	getName (void) const;
		void		setName (std::string name);
		void		announce (void) const;
};

//funciones fuera de la clase
Zombie*	newZombie(std::string name);
void	randoChump(std::string name);

#endif
