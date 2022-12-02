#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {

	public:
		Cure ();
		Cure (std::string const &type);
		Cure (const Cure &obj);
		~Cure ();

		Cure	*clone() const;
		void	use(ICharacter& target);

};

#endif
