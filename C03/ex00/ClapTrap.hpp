#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	private:
		std::string			Name;
		unsigned int        Hitpoints;
		unsigned int        EnergyPoints;
		unsigned int        AttackDamage;
	
	public:
		ClapTrap ();
		ClapTrap (std::string _Name);
		~ClapTrap ();
		ClapTrap (const ClapTrap &obj);

		ClapTrap &operator= (const ClapTrap &obj);

		std::string     getName() const;
		void            setName(std::string str);
		unsigned int    getHitpoints() const;
		void            setHitpoints(unsigned int num);
		unsigned int    getEnergyPoints() const;
		void            setEnergyPoints(unsigned int num);
		unsigned int    getAttackDamage() const;
		void            setAttackDamage(unsigned int num);
		

		void    attack (std::string const &target);
		void    takeDamage (unsigned int amount);
		void    beRepaired (unsigned int amount);

};

//external functions



#endif