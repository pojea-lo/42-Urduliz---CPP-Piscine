#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap: public virtual ClapTrap {

	public:
		FlagTrap();
		FlagTrap(std::string _Name);
		~FlagTrap();
		FlagTrap(const FlagTrap &obj);

		void    attack (std::string const &target);
		void	highFiveGuys();

};

#endif
