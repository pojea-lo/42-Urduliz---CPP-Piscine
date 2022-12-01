#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria {

	protected:
		std::string		type;

	public:
		AMateria ();
		AMateria (std::string const &type);
		AMateria (const AMateria &obj);
		virtual ~AMateria ();

		std::string			const &getType() const;
		void				setType(std::string _type);

		AMateria 			&operator= (const AMateria &obj);
		
		virtual AMateria	*clone() const = 0;
//		virtual void		use(ICharacter &target);

};

#endif
