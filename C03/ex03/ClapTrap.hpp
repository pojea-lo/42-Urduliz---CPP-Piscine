#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	private:
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

		virtual std::string     getName() const;
		virtual void            setName(std::string str);
		virtual unsigned int    getHitpoints() const;
		virtual void            setHitpoints(unsigned int num);
		virtual unsigned int    getEnergyPoints() const;
		virtual void            setEnergyPoints(unsigned int num);
		virtual unsigned int    getAttackDamage() const;
		virtual void            setAttackDamage(unsigned int num);
		

		void    attack (std::string const &target);
		void    takeDamage (unsigned int amount);
		void    beRepaired (unsigned int amount);

		void	printClap () const;
		void	chHitpoints(ClapTrap const &obj);
};

//external functions

ClapTrap	ft_lifeComp(ClapTrap *obj);

#endif
