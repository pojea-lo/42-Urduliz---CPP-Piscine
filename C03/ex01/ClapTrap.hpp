#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
		std::string			Name;
		unsigned int        Hitpoints;//puntos de vida del personaje
		unsigned int        EnergyPoints;//puntos reserva de vida
		unsigned int        AttackDamage;//potencia de fuego
	
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

		void	printClap () const;
		void	chHitpoints(ClapTrap const &obj);
};

//external functions

ClapTrap	ft_lifeComp(ClapTrap *obj);

#endif
