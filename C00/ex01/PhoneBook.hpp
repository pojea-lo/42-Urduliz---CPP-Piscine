#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class	PhoneBook {

	private:

		Contact	_list[8];
//		Contact	actual;
//		int		size;

	public:

		PhoneBook (void);
//		PhoneBook (Contact *list, Contact actual, int size);
		~PhoneBook (void);

		Contact*	getList (void) const;
		void		setList (Contact* list);
//		Contact		getActual (void) const;
//		void		setActual (Contact actual);
//		int			getSize (void) const;
//		void		setSize (int size);

//		void	introDataList (void);
//		void	printData (void);

		void	introDataContact (int id);
//		void	addContact (int id, Contact *actual);
		void	printData ();
		void	printSingleData (int id);
		void	search (int id);
};

#endif
