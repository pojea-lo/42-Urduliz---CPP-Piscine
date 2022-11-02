#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	
	private:
		std::string	name;
		Weapon		*weaponB;

	public:
		HumanB (std::string name);
		~HumanB ();

		void setWeapon(Weapon &_weaponB);

		void attack();
};

#endif
