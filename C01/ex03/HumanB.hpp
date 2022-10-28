#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>

class HumanB {
	
	private:
		Weapon		weaponB;
		std::string	name;

	public:
		HumanB (std::string name);
		~HumanB ();

		void setWeapon(Weapon _weaponB);

		void attack() const;
};

#endif
