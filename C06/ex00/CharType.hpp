#ifndef CHARTYPE_HPP
# define CHARTYPE_HPP

#include "exception.hpp"

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

};


#endif
