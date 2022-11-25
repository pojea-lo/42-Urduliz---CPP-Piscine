#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class	PhoneBook {

	private:

		Contact	_list[8];

	public:

		PhoneBook (void);
		~PhoneBook (void);

		Contact*	getList (void) const;
		void		setList (Contact* list);
		void	introDataContact (int id);
		void	printData ();
		void	printSingleData (int id);
		void	search (int id);
};

#endif
