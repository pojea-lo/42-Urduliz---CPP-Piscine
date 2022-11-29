#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

	private:
		std::string	type;

	public:
		Animal ();
		Animal (std::string _type);
		Animal (const Animal &obj);
		virtual ~Animal () = 0;

		virtual std::string	getType () const;
		virtual void		setType (std::string _type);

		Animal		&operator= (const Animal &obj);

		virtual void		makeSound() const;
		void				printAnimal() const;

};

#endif
