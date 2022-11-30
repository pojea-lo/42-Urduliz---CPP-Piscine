#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	
	private:
		Brain		*cerebro;

	public:
		Cat ();
		Cat (const Cat &obj);
		~Cat ();

		Cat			&operator= (const Cat &obj);		

		std::string	getType () const;
		void		setType (std::string _type);
		void		makeSound() const;
		void		printCat() const;
	
};

#endif
