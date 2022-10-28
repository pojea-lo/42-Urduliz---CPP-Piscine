#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class HumanA {
	
	private:
		Weapon		weaponA;
		std::string	name;

	public:
		HumanA (std::string name, Weapon _weaponA);
		~HumanA ();

		void attack() const;
};

#endif
