#ifndef CHARTYPE_HPP
# define CHARTYPE_HPP

#include <iostream>

class CharType {

	private:
		int			n;
		std::string	tmp_str;

	public:

		CharType();
		CharType(const CharType &obj);
		~CharType();

		CharType	&operator= (const CharType &obj);

		std::string		check(const std::string &str);
		int				count(const std::string &str);

};


#endif
