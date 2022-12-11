#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScravTrap.hpp"

//class DiamondTrap: public ScravTrap, public FlagTrap {
class DiamondTrap: public FlagTrap, public ScravTrap {

	private:
		std::string		Name;

	public:
		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap();

		void	attack (std::string const &target);
		void	printClap();
		void	whoAmI ();

};

#endif

