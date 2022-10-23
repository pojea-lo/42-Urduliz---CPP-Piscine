#ifndef CONTACT_H
 #define CONTACT_H

#include <iostream>

class 	Contact {

	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkestSecret;

	public:

		Contact (void);
		Contact (std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret);
		~Contact (void);

		std::string	getFirstName (void) const;
		void		setFirstName (std::string firstName);
		std::string	getLastName (void) const;
		void		setLastName (std::string lastName);
		std::string	getNickname (void) const;
		void		setNickname (std::string nickname);
		std::string	getPhone (void) const;
		void		setPhone (std::string phone);
		std::string	getDarkestSecret (void) const;
		void		setDarkestSecret (std::string darkestSecret);

};

#endif
