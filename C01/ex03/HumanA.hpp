#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	
	private:
		std::string	name;
		Weapon		&weaponA;

	public:
		HumanA (std::string name, Weapon &_weaponA);
		~HumanA ();

		void attack();
};

#endif
