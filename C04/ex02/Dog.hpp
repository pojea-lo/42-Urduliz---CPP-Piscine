#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	
	private:
		std::string	type;
		Brain	*cer;

	public:
		Dog ();
		Dog (const Dog &obj);
		~Dog ();

		std::string	getType () const;
		void		setType (std::string _type);
		void		makeSound() const;
	
};

#endif
