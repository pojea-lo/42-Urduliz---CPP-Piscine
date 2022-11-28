#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
	
	private:
		std::string	type;

	public:
		Cat ();
		Cat (const Cat &obj);
		~Cat ();

		std::string	getType () const;
		void		setType (std::string _type);
		void		makeSound () const;
	
};

#endif
