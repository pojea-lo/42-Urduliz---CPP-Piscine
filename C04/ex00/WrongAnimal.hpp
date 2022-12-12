#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

	protected:

		std::string	type;

	public:
		WrongAnimal ();
		WrongAnimal (std::string _type);
		WrongAnimal (const WrongAnimal &obj);
		~WrongAnimal ();

		std::string	getType () const;
		void		setType (std::string _type);

		WrongAnimal		*operator= (const WrongAnimal *obj);

		void		makeSound() const;

};

#endif
