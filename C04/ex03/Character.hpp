#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter {

	private:
		AMateria		*potions[4];
		std::string		Name;

	public:
		Character ();
		Character (std::string _Name);
		Character (const Character &obj);
		virtual ~Character();

		Character		&operator= (const Character &obj);
		void			setName(std::string const &_Name);

		std::string 	const &getName() const;
		void 			equip(AMateria* m);
		void 			unequip(int idx);
		void 			use(int idx, ICharacter& target);

		void			printPotions() const;		
		void			printPtrPotions() const;		
};

#endif
