#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public virtual ClapTrap {

	public:
		ScravTrap();
		ScravTrap(std::string _Name);
		~ScravTrap();
		ScravTrap (const ScravTrap &obj);

		void    attack (std::string const &target);
		void	guardGate();

};

#endif
