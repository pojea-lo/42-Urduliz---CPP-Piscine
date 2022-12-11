#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	
	private:
		Brain	*cer;

	public:
		Dog ();
		Dog (const Dog &obj);
		~Dog ();

		Dog			&operator= (const Dog &obj);

		std::string	getType () const;
		void		setType (std::string _type);
		void		makeSound() const;
	
};

#endif
